#include <stdio.h>
#define MAX 9999

struct proc{
    int pno,at,bt,tat,wt,rt,ct;
};

struct proc read(int i){
        struct proc p;
        p.pno=i+1;
        
        printf("Enter the arrival time:");
        scanf("%d",&p.at);
        printf("Enter the burst time:");
        scanf("%d",&p.bt);
        p.rt=p.bt;
        return p;
}

void main(){
    
    int n,i,j,time,s;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    
    struct proc p[10],temp;
    int remain=0;
    
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
    
    p[9].rt=MAX;
    for(time=0;remain!=n;time++){
        s=9;
        for(i=0;i<n;i++){
            if(p[i].rt>0 && p[i].rt<p[s].rt && p[i].at<=time){
                  s=i;
            }
        }
        
        p[s].rt--;
        if(p[s].rt==0){
            remain++;
            p[s].ct=time+1;
            p[s].tat=p[s].ct-p[s].at;
            p[s].wt=p[s].tat-p[s].bt;
        }
    }
    
    printf("\nPID\tAT\tBT\tTAT\tWT\tCT\n");
    for(i=0;i<n;i++){
            p[i].tat=p[i].ct-p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
            printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i].pno,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].ct);
            
        }

}
