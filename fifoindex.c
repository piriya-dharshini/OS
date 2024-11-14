#include <stdio.h>
#include <stdbool.h>

bool ispageinframe(int frames[],int num_frame,int page){
    for(int i=0;i<num_frame;i++){
        if(frames[i]==page){
            return true;
        }
    }
    return false;
}
void fifo(int pages[],int num_pages,int frames[],int num_frames){
        int fifoindex=0;
        int pagefault=0;
        
        for(int i=0;i<num_frames;i++){
            frames[i]=-1;
        } 
        
        for(int i=0;i<num_pages;i++){
            int page=pages[i];
            if(!ispageinframe(frames,num_frames,page)){
                frames[fifoindex]=page;
                fifoindex=(fifoindex+1)%num_frames;
                pagefault++;
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
      
      fifo(pages,no_pages,frames,no_of_frames);
}
