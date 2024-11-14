#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>


#define buffer_size 5
#define produce_count 7

int buffer[buffer_size];
int in=0;
int out=0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void* producer(void* arg){
      for(int i=0;i<produce_count;i++){
          int item=rand()%100;
          sem_wait(&empty);
          pthread_mutex_lock(&mutex);
          
          buffer[in]=item;
          in=(in+1)%buffer_size;
          printf("The producer %d has produced %d \n",i,item);
          pthread_mutex_unlock(&mutex);
          sem_post(&full);
          sleep(2);
      }
      return NULL;
}

void* consumer(void* arg){
      for(int i=0;i<produce_count;i++){

          sem_wait(&full);
          pthread_mutex_lock(&mutex);
          int item=buffer[out];
          printf("The consumer %d has consumed %d \n",i,item);
          out=(out+1)%buffer_size;
          pthread_mutex_unlock(&mutex);
          sem_post(&empty);
          sleep(2);
      }
      return NULL;
}
void main(){
      pthread_t prods,cons;
      
      sem_init(&empty,0,buffer_size);
      sem_init(&full,0,0);
      pthread_mutex_init(&mutex,NULL);
      
      pthread_create(&prods,NULL,producer,NULL);
      pthread_create(&cons,NULL,consumer,NULL);
      
      pthread_join(prods,NULL);
      pthread_join(cons,NULL);
      
      sem_destroy(&empty);
      sem_destroy(&full);
      pthread_mutex_destroy(&mutex);

}
