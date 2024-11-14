#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(){
    
    key_t key=ftok("shmfile1",65);
    int shmid=shmget(key,1024,0666);
    
    char *str=(char *) shmat(shmid,(void *)0,0);

    printf("The read:%s",str);
    
    shmdt(str);
    
    return 0;
}
