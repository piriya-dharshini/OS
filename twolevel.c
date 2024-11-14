#include <stdio.h>

#define MAX_DIRECTORY 5
#define MAX_FILES 10

typedef struct File{
      char* filename;
}File;

typedef struct Directory{
        char* dname;
        File files[MAX_FILES];
        int f_ct;
} Directory;

int ct=0;
Directory filesystem[MAX_DIRECTORY];

void add_dir(char* dname){
      filesystem[ct].dname=dname;
      filesystem[ct].f_ct = 0;  // Initialize file count
      ct++;
}

void add_files(char* dname,char* filename){
       
      for(int i=0;i<ct;i++){
          if(filesystem[i].dname==dname){
                int l=filesystem[i].f_ct;
                filesystem[i].files[l].filename=filename;
                filesystem[i].f_ct++;
                break;
          }
      }

}

int main(){
      
    add_dir("D1");
    add_files("D1","f1");
    add_files("D1","f2");
    
    add_dir("D2");
    add_files("D2","f1");
    add_files("D2","f2");
    add_files("D2","f3");
    
    for(int i=0;i<ct;i++){
          printf("|->%s\n",filesystem[i].dname);
          for(int j=0;j<filesystem[i].f_ct;j++){
                printf("\t|-->%s\n",filesystem[i].files[j].filename);
          }
      }
    
}
