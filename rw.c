#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

pthread_mutex_t read_count_mutex;
pthread_mutex_t resource_mutex;

int shared_data=0;
int read_count=0;

void* reader(void* arg){
      int id=*(int*)arg;
      
      while(1){
          pthread_mutex_lock(&read_count_mutex);
          read_count++;
          if (read_count==1){
              pthread_mutex_lock(&resource_mutex);
          }
          pthread_mutex_unlock(&read_count_mutex);
          printf("The reader %d reads the shared data %d\n",id,shared_data);
          sleep(1);
          pthread_mutex_lock(&read_count_mutex);
          read_count--;
          if (read_count==0){
              pthread_mutex_unlock(&resource_mutex);
          }
          pthread_mutex_unlock(&read_count_mutex);
          sleep(1);
      }
      return NULL;
  }
void* writer(void* arg){
      int id=*(int*)arg;
      
      while(1){
          pthread_mutex_lock(&resource_mutex);
          shared_data+=id;
          printf("The writer %d changed the shared data to %d\n",id,shared_data);
          sleep(2);
          pthread_mutex_unlock(&resource_mutex);
          sleep(2);
      }
      
      return NULL;

}
void main(){
      int num_readers=5;
      int num_writers=2;
      
      pthread_t readers[num_readers];
      pthread_t writers[num_writers];
      
      pthread_mutex_init(&resource_mutex,NULL);
      pthread_mutex_init(&read_count_mutex,NULL);
      
      int ids[num_readers+num_writers];
      
      for(int i=0;i<num_readers;i++){
          ids[i]=i+1;
          pthread_create(&readers[i],NULL,reader,&ids[i]);
      }
      
      for(int i=0;i<num_writers;i++){
          ids[num_readers+i]=i+1;
          pthread_create(&writers[i],NULL,writer,&ids[num_readers+i]);
      }

      for(int i=0;i<num_readers;i++){
            pthread_join(readers[i],NULL);
      }
      for(int i=0;i<num_writers;i++){
            pthread_join(writers[i],NULL);
      }
}
