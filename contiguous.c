#include<stdio.h>


void contiguous(int memory[],int size,int process[],int num_processes){
    
    int start=0;
    int curr_file_size;
    for(int i=0;i<num_processes;i++){
        
        curr_file_size=process[i];
        printf("%d",curr_file_size);
        if(start+curr_file_size<=size){
            for(int j=0;j<curr_file_size;j++){
                  memory[start+j]=i+1;
            }
            printf("%d",start);
            printf("the process %d is allocated from %d to %d\n",i,start,start+curr_file_size);
            start+=curr_file_size;
        }
    }
}
int main(){
    int process[4]={3,4,5,2};
    int memory[10]={0};
    
    contiguous(memory,10,process,4);
}
