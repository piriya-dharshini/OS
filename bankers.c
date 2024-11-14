#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

//define allocation,maximum,available
int available[NUM_RESOURCES]={3,3,2};

// Maximum demand of each process
int maximum[NUM_PROCESSES][NUM_RESOURCES] = {
    {7,5,3},
    {3,2,2},
    {9,0,2},
    {2,2,2},
    {4,3,3}
};

// Allocation matrix (resources currently allocated to each process)
int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
    {0,1,0},
    {2,0,0},
    {3,0,2},
    {2,1,1},
    {0,0,2}
};


int need[NUM_PROCESSES][NUM_RESOURCES];
int waitqueuecount=0;
int waitqueue[NUM_PROCESSES];

void calculateneed(){
    for(int i=0;i<NUM_PROCESSES;i++){
        for(int j=0;j<NUM_RESOURCES;j++){
            need[i][j]=maximum[i][j]-allocation[i][j];
        }
    }

}

bool canexecute(int process){
    for(int j=0;j<NUM_RESOURCES;j++){
        if(need[process][j]>available[j]){
            return false;
        }
    }
    return true;
}

void executeprocess(int process){
  printf("Process %d is executing\n",process);
    for(int j=0;j<NUM_RESOURCES;j++){
         available[j]+=need[process][j];
         allocation[process][j]=0;
         maximum[process][j]=0;
        }
}

void addtowaitqueue(int process){
    waitqueue[waitqueuecount++]=process;
    printf("The process %d is added to wait queue\n",process);
}

void executewaitqueue(){
    int i=0;
    while(i<waitqueuecount){
          int process=waitqueue[i];
          if(canexecute(process)){
              executeprocess(process);
              for(int j=i;j<waitqueuecount;j++){
                  waitqueue[j]=waitqueue[j+1];                  
              }
              waitqueuecount--;
          }
          else{
              i++;
          }
    }
}
void main(){
    calculateneed();
    
    for(int i=0;i<NUM_PROCESSES;i++){
        if(canexecute(i)){
            executeprocess(i);
        }
        else{
            addtowaitqueue(i);
        }
     }   
        executewaitqueue();
        
        if(waitqueuecount==0){
            printf("alll the processes are allocated\n");
  
        }
        
        else{
          printf("No safe sequence found\n");
        }
    }
