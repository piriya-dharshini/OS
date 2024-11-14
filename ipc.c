#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(){
    int pipefds[2];
    pid_t pid;
    char write_msg[]="Hello i am piriya";
    char read_msg[100];
    
    if(pipe(pipefds)==-1){
        printf("Error");
    }
    pid=fork();
    if(pid==0){
        close(pipefds[1]);
        read(pipefds[0],read_msg,sizeof(read_msg));
        printf("The pipe is read : %s\n",read_msg);
        close(pipefds[0]);
    }
    else{
        close(pipefds[0]);
        write(pipefds[1],write_msg,strlen(write_msg)+1);
        printf("The pipe is written\n");
        close(pipefds[1]);
    }
}
