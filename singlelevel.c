#include <stdio.h>

#define MAX_DIRECTORY 5
#define MAX_FILES 10

typdef struct File{
      char filename;
}File;

typedef struct Directory{
        char dname;
        FILE files[MAX_FILES];
}Directory;

int ct=0;
Directory filesystem[MAX_DIRECTORY];

void add_dir(char dname){
      Directory D1.dname=dname;
      
      filesystem[ct]=D1;
}
