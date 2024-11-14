#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_FILES 5

typedef struct File {
    int indexblock[MAX_BLOCKS];
    int filesize;
} File;

void indexs(int files[], int num_processes, int num_blocks) {
    File filesystem[MAX_FILES];
    int blockindex = 0;

    for (int i = 0; i < num_processes; i++) {
        filesystem[i].filesize = files[i];


        if (blockindex + files[i] <= num_blocks) {
            printf("Allocating File %d of size %d blocks: ", i + 1, files[i]);
  
            for (int j = 0; j < files[i]; j++) {
                filesystem[i].indexblock[j] = blockindex++;
                printf("%d ", filesystem[i].indexblock[j]);  // Display each block allocated
            }
            
        } 
    }
    // Display the block allocation status
    printf("\nBlock Allocation Status:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("File %d: ", i + 1);
        for (int j = 0; j < filesystem[i].filesize; j++) {
            printf("%d ", filesystem[i].indexblock[j]);
        }
        printf("\n");
    }
}

int main() {
    int files[4] = {3, 4, 5, 2};  // Sizes of the files (in blocks)
    
    // Perform the indexed allocation and display the status
    indexs(files, 4, 10);
    
    return 0;
}

