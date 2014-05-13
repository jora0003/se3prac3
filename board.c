#include <stdio.h>
#include <stdlib.h>
#include "2048.h"

int **board_create(int size)
{
  int i;
  // make sure size of board is sensible
  if (size<1||size>255) return NULL;

  int **board=calloc(size,sizeof(int *));
  if (!board) return NULL;
  for(i=0;i<size;i++) {
    board[i]=calloc(size,sizeof(int));
    if (!board[i]) return NULL;
  }
  return board;
}

int board_display(int size,int **board)
{
  // make sure size of board is sensible
  if (size<1||size>255) return -1;
  
  int x,y;
  
  for(y=0;y<size;y++) {    
    for(x=0;x<size;x++) {
      if (board[x][y]) printf("[% 5d]",board[x][y]);
      else printf("[     ]");
    }
    printf("\n");
  }
  return 0;
}

int board_read_column(int size, int **board, int column, int *column_Array){
   if (!board || size<1||size>255 || !column_Array) return -1;
   int index = 0;
   for(index = 0; index < size; ++index)
   {
      column_Array[index] =  board[index][column];
   }
   return 0;
}

int board_set_column(int size, int **board, int column, int *column_Array){
   if (!board || size<1||size>255 || !column_Array) return -1;
   int index = 0;
   for(index = 0; index < size; ++index)
   {
      board[index][column] = column_Array[index];
   }
   return 0;
}
int board_spawn_tile(int size, int **board)
{
  if (!board || size<1||size>255) return -1;
  
  int values[2] = {2, 4};
  int i,j,s=1;  
    
  
  while(s) {
  	
  	int row = rand() % size;
     int col = rand() % size;
  	
  	 if(board[row][col] == 0)
     {
        board[row][col] = values[rand() % 2];
        return 0;
     }
  	else if(board[row][col] != 0){ 
  		 for(i=0;i<4;++i){
	             for(j=0;j<4;++j){
		            if(board[i][j]==0){
		            	board[i][j]=values[rand() % 2];
		            	return 0;
		            }
		                  	
				 }
	    	}
	  }
	 break;	
										   
}
return -2;     
}
