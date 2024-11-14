#include <stdio.h>
int q[10],n,front=-1,rear=-1;

struct proc{
     int at,bt,ct,tat,wt,done,rt,pno;
};

void enqueue(int i){
      if(rear==10){
          printf("Overflow");
      }
      rear++;
      q[rear]=i;
      if(front==-1){
          front=0;
      }
}

int dequeue(){
    if(front==-1){
          printf("Underflow");
    }
    int item=q[front];
    if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
    return item;
}

int isinqueue(int i){
    int k;
    for(k=front;k<=rear;k++){
        if(q[k]==i){
            return 1;
        }
    }
    return 0;
}

struct proc read(int i){
        struct proc p;
        p.pno=i+1;
        printf("Enter the arrival time:");
        scanf("%d",&p.at);
        printf("Enter the burst time:");
        scanf("%d",&p.bt);
        p.rt=p.bt;
        p.done=0;
        return p;
}

void main(){
    int n,i,j,remaining,tq,time;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    
    printf("Enter the time quantum:");
    scanf("%d",&tq);
    
    struct proc p[10],temp;
    
    for(i=0;i<n;i++){
        p[i]=read(i);
    }
    
    for(i=0;i<n-1;i++){
      for(j=0;j<n-i-1;j++){
          if(p[j].at>p[j+1].at){
              temp=p[j];
              p[j]=p[j+1];
              p[j+1]=temp;
          }
      }
    }
    
    remaining=n;
    enqueue(0);
    for(time=p[0].at;remaining!=0;){
        i=dequeue();
        printf("%d",i);
        if(p[i].rt<=tq){
            time+=p[i].rt;
            p[i].ct=time;
            p[i].done=1;
            p[i].tat=p[i].ct-p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
            p[i].rt=0;
            remaining--;
            printf("p%d-->",p[i].pno);
            for(j=0;j<n;j++){
                if(p[j].done!=1 && isinqueue(j)!=1 && p[j].at<=time){
                      enqueue(j);
                }
            }
        
        }
        else{
            p[i].rt-=tq;
            time+=tq;
            printf("p%d-->",p[i].pno);
            for(j=0;j<n;j++){
                if(j!=i  &&p[j].done!=1 && isinqueue(j)!=1 && p[j].at<=time){
                      enqueue(j);
                }
            }
            
            enqueue(i);
        }
      
    }
    
    printf("\nPID\tAT\tBT\tTAT\tWT\tCT\n");
    for(i=0;i<n;i++){
            printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i].pno,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].ct);
            
        }

  
}

