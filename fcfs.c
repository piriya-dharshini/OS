#include <stdio.h>

int all_done(int done[],int n){
    for (int i=0;i<n;i++){
        if(done[i]==0){
            return 0;
        }
    
    }
    return 1;

}
void main(){
    int n;
    printf("Enter the total processes:");
    scanf("%d",&n);
    
    int pid[n],at[n],bt[n],st[n],ct[n],tat[n],wt[n],done[n];
    
    for(int i=0;i<n;i++){
        printf("Enter the process id:");
        scanf("%d",&pid[i]);
        printf("Enter the arrival time:");
        scanf("%d",&at[i]);
        printf("Enter the burst time:");
        scanf("%d",&bt[i]);
        done[i]=0;
    }

    for(int i=0;i<n;i++){
        printf("--------");
    }
    
    printf("\n");
    
    int clock=0;
    while(1){
          int flag=0;
          for(int i=0;i<n;i++){
                if(at[i]<=clock && done[i]!=1){
                    st[i]=clock;
                    ct[i]=st[i]+bt[i];
                    clock=ct[i];
                    done[i]=1;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];
                    printf("P%d",pid[i]);
                    printf("\t|");
                }
                else{
                  flag++;
                }
          }
          
          if(flag==n){
              clock++;
          }
          
          if(all_done(done,n)==1){
              break;
          }
      
    }
    
     printf("\n");
     
     for(int i=0;i<n;i++){
        printf("\t|");
        printf("%d",st[i]);
     }
     printf("\n");
     
     for(int i=0;i<n;i++){
        printf("--------");
    }
    
}
