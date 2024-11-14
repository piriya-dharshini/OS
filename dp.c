#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>


#define NUM_PHILOSOPHERS 5

sem_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];
int philosophers_ids[NUM_PHILOSOPHERS];

void* philosopher(void* arg){
      int id= *(int *) arg;
      
      while(1){
          printf("Philosopher %d is thinking\n",id);
          sleep(2);
          
          printf("Philosopher %d is hungry\n",id);
          

          sem_wait(&forks[id]);
          sem_wait(&forks[(id+1)%NUM_PHILOSOPHERS]);
          
          printf("Philosopher %d is eating\n",id);
          sleep(2);
          
          sem_post(&forks[id]);
          sem_post(&forks[(id+1)%NUM_PHILOSOPHERS]);
          printf("Philosopher %d is finished eating\n",id);
      }
      
      return NULL;

}

void main(){
      
      for(int i=0;i<NUM_PHILOSOPHERS;i++){
          sem_init(&forks[i],0,1);
          philosophers_ids[i]=i;
      }
      
      for(int i=0;i<NUM_PHILOSOPHERS;i++){
          pthread_create(&philosophers[i],NULL,philosopher,&philosophers_ids[i]);
      }
      
      for(int i=0;i<NUM_PHILOSOPHERS;i++){
          pthread_join(philosophers[i],NULL);
          
      }
      
      for(int i=0;i<NUM_PHILOSOPHERS;i++){
          sem_destroy(&forks[i]);
      }
    
}
