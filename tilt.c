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

  int tilt_board_down(int size,int **board){
  // make sure size of board is sensible
  if (size<1||size>255||!board) return -1;
  int column = 0;
  int sumDown = 0;
  for(column = 0; column < size; ++column)
  {
     int *column_Array = calloc(size, sizeof(int));
     board_read_column(size, board, column, column_Array);
     sumDown += tilt_line_Right(size, column_Array);
     board_set_column(size, board, column, column_Array);
  }
  return sumDown;
}
  
  int tilt_board_left(int size,int **board){
	
	int sumLeft;
	if (size<1||size>255||!board) return -1;
  int line = 0;
  
  for(line = 0; line < size; ++line)
  {
     sumLeft+= tilt_line_left(size, board[line]);
  }
  return sumLeft;
}
  
  int tilt_board_Right(int size,int **board){
	
	int sumRight;
	if (size<1||size>255||!board) return -1;
  int line = 0;
  
  for(line = 0; line < size; ++line)
  {
     sumRight+= tilt_line_Right(size, board[line]);
  }
  return sumRight;
	
	
}
