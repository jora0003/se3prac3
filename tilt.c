#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
 int  t=0 ; 
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left 
   
  shift_line_left(length,line);
  
  // combine tiles as required
 t=+ combine_tiles(length,line,0);
    
  shift_line_left(length,line);
  
  return t; 
}
int tilt_line_Right(int length,int *line){ 
              int sutt=0; 
  // make sure vector length is sensible
             if (length<1||length>255) return -1;

  // slide tiles to the left 
   
  shift_line_Right(length,line);
 sutt=+ combine_tiles(length,line,1);
    
  shift_line_Right(length,line);

              
            return sutt;
    
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
  
  
  int shift_line_Right(int length, int *line){
  
  	int i,y;
   int last_index = length - 1;
   int size=length;
  	
  	if (length<1||length>255 || !line) return -1;
  	
   while(size>0){
   	for (i = last_index; i > 0; i--) {
        
            if (line[i] ==0 && line[i-1]!=0 ) {
               y=line[i-1];
			   line[i]=y;
			   line[i-1]=0 ; 
			   break;
            }
        } 
		    	size--;
   }
  return 0;
  }
  
  int combine_tiles(int length,int *line,int offset){
	 int y,s=0,sum;
    
    if (length<1||length>255 || !line) return -1;
    
    if (offset==0){
    	
    	for (y = 0; y < length; y++) {

            if (line[y] == line[y+1]) {
                s=line[y]+line[y+1];
                line[y]=s;
                line[y+1]=0; 
                sum+=s;
            }
            	
        } 

    }
     if(offset==1){
     	
     	for (y = length-1; y >=0; y--) {

            if (line[y] == line[y-1]) {
                s=line[y]+line[y-1];
                line[y]=s;
                line[y-1]=0; 
                sum+=s;
            }
            	
        } 
     
     }
     return sum;
     
}

  
