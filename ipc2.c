#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(){
    int pipe1[2];
    int pipe2[2];
    pid_t c1,c2;
    char write_msg1[]="Hello i am piriya";
    char write_msg2[]="Hello i am navya";
    char read_msg[100];
    
    if(pipe(pipe1)==-1){
        printf("Error");
    }
    if(pipe(pipe2)==-1){
        printf("Error");
    }
    
    c1=fork();
    if(c1==0){
        c2=fork();
        if(c2==0){
            close(pipe2[1]);
            close(pipe1[0]);
            close(pipe1[1]);
            read(pipe2[0],read_msg,sizeof(read_msg)+1);
            
            close(pipe1[1]);
        }
        else{
        
        }
    }
    else{
        close(pipe2[0]);
        close(pipe2[1]);
        close(pipe1[0]);
        write(pipe1[1],write_msg1,strlen(write_msg1)+1);
        printf("The pipe is written\n");
        close(pipe1[1]);
    }
}
