#include <stdio.h>
#define MAX 9999

struct proc{
    int pno,at,bt,tat,wt,it,ct;
};

struct proc read(int i){
        struct proc p;
        p.pno=i+1;
        
        printf("Enter the arrival time:");
        scanf("%d",&p.at);
        printf("Enter the burst time:");
        scanf("%d",&p.bt);
        return p;
}

void main(){
    
    int n,i,j,min;
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

    min=0;
    for(j=1;j<n && p[j].at==p[0].at;j++){
        if(p[j].bt<p[min].bt){
            min=j;
        }
    }
    
    temp=p[0];
    p[0]=p[min];
    p[min]=temp;
    
    p[0].it=p[0].at;
    p[0].ct=p[0].it+p[0].bt;
    
    for(i=1;i<n;i++){
        
          for(j=i+1,min=i;j<n && p[j].at<=p[i-1].ct;j++){
              if(p[j].bt<p[min].bt){
                  min=j;
              }
          }
          
          temp=p[i];
          p[i]=p[min];
          p[min]=temp;
          
          if(p[i].at<=p[i-1].ct){
              p[i].it=p[i-1].ct;
          }
          else{
            p[i].it=p[i].at;
            
          }
          
          p[i].ct=p[i].it+p[i].bt;
    
    
}
    printf("\nPID\tAT\tBT\tTAT\tWT\tCT\n");
    for(i=0;i<n;i++){
            p[i].tat=p[i].ct-p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
            printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i].pno,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].ct);
            
        }

}
