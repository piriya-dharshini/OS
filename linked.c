#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_FILES 5

typedef struct Block{
    int nextblock;
}Block;

void linked(int files[],int num_processes,int num_blocks){
    Block blocks[MAX_BLOCKS];
    
    for(int i=0;i<num_blocks;i++){
          blocks[i].nextblock=-1;
    }
    
    int blockindex=0;

    for(int i=0;i<num_processes;i++){
        
        int curr_file_size=files[i];

        if(blockindex+curr_file_size<=num_blocks){
            for(int j=blockindex;j<=blockindex+curr_file_size;j++){
                  blocks[j].nextblock=(j==blockindex+curr_file_size)?-1:j+1;
            }
            blockindex+=curr_file_size;
        }
    }
    
    // Print the block chain links
    printf("\nBlock Allocation Status:\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("Block %d: Next Block -> %d\n", i, blocks[i].nextblock);
    }

}
int main(){
    int files[4]={3,4,5,2};
    
    linked(files,4,10);
}
