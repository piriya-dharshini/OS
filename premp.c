#include <stdio.h>
#define MAX 9999

struct proc{
    int pno,at,bt,tat,wt,ct,prio,rt,temp;
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
        p.rt=p.bt;
        p.temp=p.prio;
        return p;
}

void main(){
    
    int n,i,j,min,remaining,min_index,min_value,c;
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
    
    min_index=0;
    min_value=p[0].temp;
    
    for(j=0;j<n&&p[j].at<=p[0].at;j++){
        if(p[j].temp<min_value){
            min_index=j;
            min_value=p[j].temp;
        }
    }
    
    remaining=n;
    
    i=min_index;
    temp=p[i];
    p[i]=p[min_index];
    p[min_index]=temp;
    
    p[i].rt--;
    c=p[i].ct=p[i].at+1;
    if(p[i].rt==0){
        remaining--;
        p[i].temp=MAX;
    }
    
    while(remaining>0){
          min_index=0;
          min_value=p[0].temp;
          
          for(j=0;j<n&&p[j].at<=c;j++){
              if(p[j].temp<min_value){
                        min_index=j;
                        min_value=p[j].temp;
                    }
                }
                
                
                i=min_index;
                temp=p[i];
                p[i]=p[min_index];
                p[min_index]=temp;
                
                p[i].rt--;
                c=p[i].ct=c+1;
                if(p[i].rt==0){
                    remaining--;
                    p[i].temp=MAX;
                }
                
   
    }
    
    printf("\nPID\tAT\tBT\tTAT\tWT\tCT\n");
    for(i=0;i<n;i++){
            p[i].tat=p[i].ct-p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
            printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i].pno,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].ct);
            
        }
    
    
          
}
