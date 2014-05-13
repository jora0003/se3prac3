#include <stdio.h>
#include "2048.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char **argv)
{
  // Randomise random unmber generator initial state.
  srandom(time(0));
  
  int board_size=4;
  int **board=board_create(board_size);
  if (!board) {
    printf("failed to create board.\n");
    exit(0);
  }
   int score = 0;
   
    // Spawn  two times as start of game
   board_spawn_tile(board_size, board);
   board_spawn_tile(board_size, board);
  
  

  while(1) {
  	int sum = 0, t = 1;
    board_display(board_size,board);
    printf("\n Youre score: %d\n", score);
    printf("Next move? "); fflush(stdout);
    int action=read_input();
    
    switch(action) {
    case GO_LEFT:
    	
    	 sum = tilt_board_left(board_size, board);
    	 score += sum;
                  
      break;
    case GO_RIGHT:
    	
    	sum = tilt_board_Right(board_size, board);
    	 score += sum;
                   
      break;
    case GO_UP:
    	
    	sum = tilt_board_up(board_size, board);
    	 score += sum;
              	
      break;
    case GO_DOWN:
    	
    	sum = tilt_board_down(board_size, board);
    	 score += sum;
          
      break;
    case GO_NOWHERE:
    	t=0;
      break;
    case INVALID_INPUT:
    default:
      printf("Invalid input. Type l, r, u or d to tilt board.\n");
      t=0;
      break;
    }
     int w=board_won(board_size, board);
     int l= board_lost(board_size, board);
    if(w == 1)
       {
         
         printf("\nYOU WIN!!! with a score of: %d\n", score);
         break;
       }
      else if(l == 1)
       {
          
         printf("\nGAME OVER!!! with a score of: %d\n", score);
         break;
       }
    
    else if(t!=0)
    
      board_spawn_tile(board_size, board);
        
  }
  
  return 0;
}
