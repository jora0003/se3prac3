#include <stdio.h>
#include "2048.h"

int main(int argc,char **argv)
{
  int e=0;
  e|=test_shift_line_left_WhiteBox(281);
  e|=test_shift_line_left_WhiteBox(4);  
  e|=test_shift_line_Right_WhiteBox(257);
  e|=test_shift_line_Right_WhiteBox(4);
  e|= board_won_WhiteBox(260);
  e|= board_won_WhiteBox(4);
  e|=parse_input_WhiteBox("L");
  e|=parse_input_WhiteBox("X");
  e|=board_lost_WhiteBox(270);
  e|=board_lost_WhiteBox(4);
  return e;
}


int test_shift_line_left_WhiteBox(int  length ){
	
	 
	int i;
   int max_index = length - 1;
   int size=length;
	int array[4] = {1, 0, 0, 1};
	
	
 
 	if (length<1||length>255 || !array){ 
	   printf("Tilting path 1  yields PASSED.\n");
	  	 return -1;
		   
		   }
	else 
	   {
	    
		
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
	
	 		
		if ((array[0]!=1)||(array[1]!=1)||(array[2]!=0)||(array[3]!=0))
          {
      printf("FAILED: {%d,%d,%d,%d} became {%d,%d,%d,%d} instead of"
             " {%d,%d,%d,%d}\n",
             1,0,0,1,array[0],array[1],array[2],array[3],
             1,1,0,0);
                     
          } 
            else
			printf("Tilting path 2  yields PASSED.\n");
}
	 return 0; 
}

int test_shift_line_Right_WhiteBox(){
	
	int i;
	int array[4] = {1, 0, 0, 1};
	
 
 	if (length<1||length>255 || !array){ 
	   printf("Tilting path 1  yields PASSED.\n");
	  	 return -1;
		   
		   }
	else 
	     {
	     
	     
	     
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
	
		if ((array[0]!=0)||(array[1]!=0)||(array[2]!=1)||(array[3]!=1))
          {
      printf("FAILED: {%d,%d,%d,%d} became {%d,%d,%d,%d} instead of"
             " {%d,%d,%d,%d}\n",
             1,0,0,1,line[0],array[1],array[2],array[3],
             0,0,1,1);
                     
          } 
            else
			printf("Tilting path 2  yields PASSED.\n");
 	
 	}
	 return 0; 
}

int board_won(int size)
{
	
	 int  i = 0;
   int j = 0;
	
	int Board[16] = {0,0,0,0,
                          2,0,1,0,
                          0,1024,0,0,
                          0,0,0,0};
	
   if (!board || size<1||size>255) {
   printf("Tilting path 1  yields PASSED.\n");
   return -1;  }
  
  
  else{
  	
  	  
   for(i = 0; i < size; ++i)
   {
     for(j = 0; j < size; ++j)
     {
        if(board[i][j] == WIN_SCORE)
        {
            printf("Find Win value in: \n{%d,%d,%d,%d}\n{%d,%d,%d,%d}\n{%d,%d,%d,%d}\n{%d,%d,%d,%d}\n yields  Success ",
          board[0], board[1], board[2], board[3], 
          board[4], board[5], board[6], board[7],
          board[8], board[9], board[10], board[11], 
          board[12], board[13], board[14], board[15]);
          printf("Tilting  path 2 yields PASSED \n");
           return 1;
        }
     }
   }
   
   printf("Tilting  path 2 yields FAILED \n");
   
   
}


   return 0;
}


int board_lost(int size)
{
	int  i = 0;
   int j = 0;
		int Board[16] = {2,4,8,16,
                          4,8,1,4,
                          8,1024,8,16,
                          4,256,2,1};
			
   if (!board || size<1||size>255) {
   printf("Tilting path 1  yields PASSED.\n");
   return -1;}   
   
   
   else{
   
      
      for(i = 0; i < size; ++i)
   {
      for(j = 0; j < size; ++j)
      {
         if((board[i][j] == 0) || (i < size - 1 && board[i][j] == board[i+1][j]) ||(j < size - 1 && board[i][j] == board[i][j+1]) )
         {
         	
          printf("Test end game in: \n{%d,%d,%d,%d}\n{%d,%d,%d,%d}\n{%d,%d,%d,%d}\n{%d,%d,%d,%d}\n yields  Success ",
          board[0], board[1], board[2], board[3], 
          board[4], board[5], board[6], board[7],
          board[8], board[9], board[10], board[11], 
          board[12], board[13], board[14], board[15]);
          printf("Tilting  path 2 yields PASSED \n");
            return 1;
         }
      }
   }
    printf("Tilting  path 2 yields FAILED \n");
    
    
    }
   return 0;
}


int parse_input_WhiteBox(char *line)
{
  
 if (!strcasecmp(line,"l")) {
 	printf("Tilting  path 1 yields PASSED Return Value %d\n",GO_LEFT);
  	
 return GO_LEFT;  }
  if (!strcasecmp(line,"r")){
  		printf("Tilting  path 1 yields PASSED Return Value %d\n",GO_RIGHT);
  	  return GO_RIGHT; } 
  if (!strcasecmp(line,"u")){
  		printf("Tilting  path 1 yields PASSED Return Value %d\n",GO_UP);
  	  return GO_UP; }
  if (!strcasecmp(line,"d")){
  		printf("Tilting  path 1 yields PASSED Return Value %d\n",GO_DOWN);
  	   return GO_DOWN;  }
  	   
  	   
  if (line[0]==0 || strcasecmp(line,"l") || strcasecmp(line,"r") ||  strcasecmp(line,"u") ||  strcasecmp(line,"d")){  
  		
  		  printf("Tilting  path 2 yields PASSED \n    Return Value %d", INVALID_INPUT);	
 	 return INVALID_INPUT; 
}

