#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(){
    
    key_t key=ftok("shmfile1",65);
    int shmid=shmget(key,1024,0666|IPC_CREAT);
    
    char *str=(char *) shmat(shmid,(void *)0,0);
    
    char server_msg[]="Hello i am piriya";
    strcpy(str,server_msg);
    
    shmdt(str);
    
    return 0;
}
