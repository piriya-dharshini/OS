
#include <stdio.h>
#include <stdbool.h>

#define MAX 9999;
bool ispageinframe(int frames[],int num_frame,int page){
    for(int i=0;i<num_frame;i++){
        if(frames[i]==page){
            return true;
        }
    }
    return false;
}
void lru(int pages[],int num_pages,int frames[],int num_frames){
        for(int i=0;i<num_frames;i++){
            frames[i]=-1;
        } 
        
        for(int i=0;i<num_pages;i++){
            int page=pages[i];
            if(!ispageinframe(frames,num_frames,page)){
                
                int leastindex=0;
                int leastvalue=-1;
                
                for(int j=0;j<num_frames;j++){
                    if(frames[j]==-1){
                        leastindex=j;
                        break;
                    }
                
                   int lastused=MAX;
                   for(int k=i+1;k<num_pages;k++){
                      if(pages[k]==frames[j]){
                            lastused=k;
                            break;
                      }
                   }
                   
                   if(lastused>leastvalue){
                      leastindex=j;
                      leastvalue=lastused;
                   }
            }
            
            frames[leastindex]=page;
            }
        }

      for(int i=0;i<num_frames;i++){
          printf("%d\t",frames[i]);
      }
}

void main(){
      int pages[14]={7,0,1,2,0,3,0,4,2,3,2,3};
      int no_pages=14;
      int no_of_frames=4;
      int frames[4];
      
      lru(pages,no_pages,frames,no_of_frames);
}
