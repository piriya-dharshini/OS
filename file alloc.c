/*
#include <stdio.h>

void contiguous(int memory[], int total_blocks, int sizes[], int num_processes) {
    int start = 0;
    for (int i = 0; i < num_processes; i++) {
        if (start + sizes[i] <= total_blocks) { // Check if enough space is available
            for (int j = 0; j < sizes[i]; j++) {
                memory[start + j] = i + 1; // Allocate blocks to process i+1
            }
            printf("Process %d allocated from %d to %d\n", i + 1, start, start + sizes[i] - 1);
            start += sizes[i];
        } else {
            printf("Process %d cannot be allocated due to insufficient memory.\n", i + 1);
        }
    }
}

int main() {
    int total_blocks = 10;
    int memory[10] = {0}; // Initialize memory array

    int process_sizes[] = {3, 4, 2, 3}; // Sizes for each process
    int num_processes = sizeof(process_sizes) / sizeof(process_sizes[0]);

    contiguous(memory, total_blocks, process_sizes, num_processes);

    // Display the memory allocation
    for (int i = 0; i < total_blocks; i++) {
        printf("Block %d: %d\n", i, memory[i]);
    }

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 5
#define MAX_BLOCKS 10

// Structure to represent a block in linked allocation
typedef struct Block {
    int nextBlock;
} Block;

// Function for Linked Allocation
void linkedAllocation(int files[], int numFiles, int numBlocks) {
    Block blocks[MAX_BLOCKS];
    for (int i = 0; i < numBlocks; i++) {
        blocks[i].nextBlock = -1; // Initially, all blocks are free
    }

    int blockIndex = 0;
    for (int i = 0; i < numFiles; i++) {
        int fileSize = files[i];
        printf("Allocating File %d of size %d blocks\n", i + 1, fileSize);
        int firstBlock = blockIndex;
        if (blockIndex + fileSize <= numBlocks) {
            for (int j = blockIndex; j < blockIndex + fileSize; j++) {
                blocks[j].nextBlock = (j == blockIndex + fileSize - 1) ? -1 : j + 1;
                blockIndex++;
            }
            printf("File %d allocated starting from Block %d\n", i + 1, firstBlock);
        } else {
            printf("Not enough space for File %d\n", i + 1);
        }
    }

    printf("\nBlock Allocation Status:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: Next Block -> %d\n", i, blocks[i].nextBlock);
    }
}

int main() {
    int files[MAX_FILES] = {3, 4, 2, 5, 3}; // Sizes of files in blocks
    int numFiles = 5;
    int numBlocks = 10;

    linkedAllocation(files, numFiles, numBlocks);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 5
#define MAX_BLOCKS 10

// Structure for Indexed Allocation
typedef struct File {
    int indexBlock[MAX_BLOCKS];
    int fileSize;
} File;

// Function for Indexed Allocation
void indexedAllocation(int files[], int numFiles, int numBlocks) {
    File fileSystem[MAX_FILES];

    int blockIndex = 0;
    for (int i = 0; i < numFiles; i++) {
        fileSystem[i].fileSize = files[i];
        printf("Allocating File %d of size %d blocks\n", i + 1, files[i]);
        if (blockIndex + files[i] <= numBlocks) {
            printf("File %d allocated to blocks: ", i + 1);
            for (int j = 0; j < files[i]; j++) {
                fileSystem[i].indexBlock[j] = blockIndex++;
                printf("%d ", fileSystem[i].indexBlock[j]);
            }
            printf("\n");
        } else {
            printf("Not enough space for File %d\n", i + 1);
        }
    }

    printf("\nBlock Allocation Status:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("File %d: Blocks -> ", i + 1);
        for (int j = 0; j < fileSystem[i].fileSize; j++) {
            printf("%d ", fileSystem[i].indexBlock[j]);
        }
        printf("\n");
    }
}

int main() {
    int files[MAX_FILES] = {3, 4, 2, 5, 3}; // Sizes of files in blocks
    int numFiles = 5;
    int numBlocks = 10;

    indexedAllocation(files, numFiles, numBlocks);

    return 0;
}


