#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left

  // combine tiles as required

  return 0;
}

int shift_line_left(int length, int *line){
  	int i,y;
   int max_index = length - 1;
   int size=length;
  	
  	if (length<1||length>255 || !line) return -1;
  	
   while(size>0){
   	for (i = 0; i < max_index; i++) {
        
            if (line[i] ==0 && line[i+1]!=0 ) {
               y=line[i+1];
			   line[i]=y;
			   line[i+1]=0; 
            }
            
        } 
		size--;
   }
    return 0; 	
  }
