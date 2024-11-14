#include <stdio.h>
#define MAX 9999

struct proc{
    int pno,at,bt,tat,wt,ct,prio,status;
};

struct proc read(int i){
        struct proc p;
        p.pno=i+1;
        printf("Enter the arrival time:");
        scanf("%d",&p.at);
        printf("Enter the burst time:");
        scanf("%d",&p.bt);
        printf("Enter the priority:");
        scanf("%d",&p.prio);
        p.status=0;
        return p;
}

void main(){
    
    int n,i,j,min,remaining,ct,s;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    
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
    p[9].prio=MAX;
    for(ct=p[0].at;remaining!=0;){
        s=9;
        for(i=0;i<n;i++){
            if(p[i].prio<p[s].prio && p[i].at<=ct && p[i].status!=1){
                s=i;
            }
        }
        
        remaining--;
        p[s].ct=ct=ct+p[s].bt;
        p[s].tat=p[s].ct-p[s].at;
        p[s].wt=p[s].tat-p[s].bt;
        p[s].status=1;
    }
    
    printf("\nPID\tAT\tBT\tTAT\tWT\tCT\n");
    for(i=0;i<n;i++){
            p[i].tat=p[i].ct-p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
            printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i].pno,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].ct);
            
        }
}
