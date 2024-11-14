#include <stdio.h>
#include <string.h>

#define MAX_DIRECTORY 5
#define MAX_FILES 10
#define MAX_SHARED_FILES 10

typedef struct File {
    char* filename;  // File name
    int shared;      // Flag to mark if the file is shared (1 = shared, 0 = not shared)
} File;

typedef struct Directory {
    char* dname;      // Directory name
    File files[MAX_FILES];  // Files in this directory
    int f_ct;         // File count in this directory
} Directory;

int ct = 0;  // Directory count
Directory filesystem[MAX_DIRECTORY];
File shared_files[MAX_SHARED_FILES];  // Array to hold shared files
int shared_count = 0;  // Count of shared files

// Function to add a directory
void add_dir(char* dname) {
    filesystem[ct].dname = dname;
    filesystem[ct].f_ct = 0;  // Initialize file count
    ct++;
}

// Function to add a file to a directory
void add_file(char* dname, char* filename, int shared) {
    // If the file is shared, add it to the shared file array
    if (shared) {
        shared_files[shared_count].filename = filename;
        shared_files[shared_count].shared = 1;
        shared_count++;
    }

    // Add the file to the directory
    for (int i = 0; i < ct; i++) {
        if (strcmp(filesystem[i].dname, dname) == 0) {
            filesystem[i].files[filesystem[i].f_ct].filename = filename;
            filesystem[i].files[filesystem[i].f_ct].shared = shared;
            filesystem[i].f_ct++;
            break;
        }
    }
}

// Function to display the filesystem structure
void display_filesystem() {
    for (int i = 0; i < ct; i++) {
        printf("|-> %s\n", filesystem[i].dname);
        for (int j = 0; j < filesystem[i].f_ct; j++) {
            printf("\t|--> %s (Shared: %d)\n", filesystem[i].files[j].filename, filesystem[i].files[j].shared);
        }
    }

    // Display shared files
    if (shared_count > 0) {
        printf("\nShared Files:\n");
        for (int i = 0; i < shared_count; i++) {
            printf("\t|--> %s\n", shared_files[i].filename);
        }
    }
}

int main() {
    // Adding directories
    add_dir("D1");
    add_dir("D2");
    
    // Adding files to directories
    add_file("D1", "f1", 0);  // Not shared
    add_file("D1", "f2", 1);  // Shared
    add_file("D2", "f1", 0);  // Not shared
    add_file("D2", "f2", 1);  // Shared
    add_file("D2", "f3", 0);  // Not shared

    // Display the filesystem structure
    display_filesystem();

    return 0;
}

