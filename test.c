#include <stdio.h>
#include "2048.h"

int line_vector_test(int i1,int i2,int i3,int i4,char *msg,
                int o1,int o2,int o3,int o4, int (*func)(int,int *))
{
  int list[4]={i1,i2,i3,i4};
  if (msg) printf("%s - ",msg); 
  else {
    printf("Tilting {%d,%d,%d,%d} left yields {%d,%d,%d,%d} - ",
             i1,i2,i3,i4,o1,o2,o3,o4);
  }
  fflush(stdout);
  func(4,list);
  if ((list[0]!=o1)||(list[1]!=o2)||(list[2]!=o3)||(list[3]!=o4))
    {
      printf("FAILED: {%d,%d,%d,%d} became {%d,%d,%d,%d} instead of"
             " {%d,%d,%d,%d}\n",
             i1,i2,i3,i4,list[0],list[1],list[2],list[3],
             o1,o2,o3,o4);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
  
}

int ttl_vector(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_left);
}

int test_tilt_left()
{
  int e=0;
  e|=ttl_vector(0,0,0,0,"Empty list is empty after shift",0,0,0,0);
  e|=ttl_vector(1,0,0,0,"Value on left stays on left after shift",1,0,0,0);
  e|=ttl_vector(0,0,0,1,"Value on right shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(0,0,1,0,"Value in middle shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector(1,1,1,1,"Combinations don't cascade",2,2,0,0);
  e|=ttl_vector(0,0,1,1,NULL,2,0,0,0);
  e|=ttl_vector(4,0,1,1,NULL,4,2,0,0);
  e|=ttl_vector(2,0,1,1,NULL,2,2,0,0);
  return e;
}

int ttl_vector_Right(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
	
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_Right);
}

int test_tilt_Right()
{
  int e=0;
  e|=ttl_vector_Right(0,0,0,0,"Empty list is empty after shift",0,0,0,0);
  e|=ttl_vector_Right(1,0,0,0,"Value on left stays on left after shift",0,0,0,1);
  e|=ttl_vector_Right(0,0,0,1,"Value on right shifts to left edge after shift",0,0,0,1);
  e|=ttl_vector_Right(0,0,1,0,"Value in middle shifts to left edge after shift",0,0,0,1);
  e|=ttl_vector_Right(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector_Right(1,1,1,1,"Combinations don't cascade",0,0,2,2);
  e|=ttl_vector_Right(0,0,1,1,NULL,0,0,0,2);
  e|=ttl_vector_Right(4,0,1,1,NULL,0,0,4,2);
  e|=ttl_vector_Right(2,0,1,1,NULL,0,0,2,2);
  return e;
}



int test_shift_line_left()
{
  int e=0;
  e|=ttl_vector_shift_line_left(0,0,0,0,"Empty list is empty after shift_line_left",0,0,0,0);
  e|=ttl_vector_shift_line_left(1,0,0,0,"Value on left stays on left after shift_line_left",1,0,0,0);
  e|=ttl_vector_shift_line_left(0,0,0,1,"Value on right shifts to left edge after shift_line_left",1,0,0,0);
  e|=ttl_vector_shift_line_left(0,0,1,0,"Value in middle shifts to left edge after shift_line_left",1,0,0,0);
  e|=ttl_vector_shift_line_left(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector_shift_line_left(1,1,1,1,"Combinations don't cascade",1,1,1,1);
  e|=ttl_vector_shift_line_left(0,0,1,1,NULL,1,1,0,0);
  e|=ttl_vector_shift_line_left(4,0,1,1,NULL,4,1,1,0);
  e|=ttl_vector_shift_line_left(0,1,0,1,NULL,1,1,0,0); 
  return e;
}


int ttl_vector_shift_line_left(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
	
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,shift_line_left);
}




int test_shift_line_Right()
{
  int e=0;
  e|=ttl_vector_shift_line_Right(0,0,0,0,"Empty list is empty after shift_line_Right",0,0,0,0);
  e|=ttl_vector_shift_line_Right(0,0,0,1,"Value on Right stays on Right after shift_line_Right",0,0,0,1);
  e|=ttl_vector_shift_line_Right(1,0,0,0,"Value on left shifts to Right edge after shift_line_Right",0,0,0,1);
  e|=ttl_vector_shift_line_Right(0,0,1,0,"Value in middle shifts to Right edge after shift_line_Right",0,0,0,1);
  e|=ttl_vector_shift_line_Right(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector_shift_line_Right(1,1,1,1,"Combinations don't cascade",1,1,1,1);
  e|=ttl_vector_shift_line_Right(0,0,1,1,NULL,0,0,1,1);
  e|=ttl_vector_shift_line_Right(4,0,1,1,NULL,0,4,1,1);
  e|=ttl_vector_shift_line_Right(0,1,0,1,NULL,0,0,1,1); 
  return e;
}


int ttl_vector_shift_line_Right(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
	
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,shift_line_Right);
}


int line_combine_vector_test(int i1,int i2,int i3,int i4,char *msg,
                int o1,int o2,int o3,int o4,int (*func)(int,int *,int),int d)
{
  int list[4]={i1,i2,i3,i4};
  if (msg) printf("%s - ",msg); 
  else {
    printf("Tilting {%d,%d,%d,%d} left yields {%d,%d,%d,%d} - ",
             i1,i2,i3,i4,o1,o2,o3,o4);
  }
  fflush(stdout);
  func(4,list,d);
  if ((list[0]!=o1)||(list[1]!=o2)||(list[2]!=o3)||(list[3]!=o4))
    {
      printf("FAILED: {%d,%d,%d,%d} became {%d,%d,%d,%d} instead of"
             " {%d,%d,%d,%d}\n",
             i1,i2,i3,i4,list[0],list[1],list[2],list[3],
             o1,o2,o3,o4);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
  
}
 

int test_combine_line_left()
{
  int e=0;
  e|=ttl_vector_combine_line_left(0,0,0,0,"Empty list is empty after combine line left",0,0,0,0);
  e|=ttl_vector_combine_line_left(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector_combine_line_left(1,0,0,0,NULL,1,0,0,0);
  e|=ttl_vector_combine_line_left(1,1,0,0,NULL,2,0,0,0);
  e|=ttl_vector_combine_line_left(0,0,1,1,NULL,0,0,2,0);
  e|=ttl_vector_combine_line_left(0,0,0,1,NULL,0,0,0,1);
  e|=ttl_vector_combine_line_left(1,0,1,1,NULL,1,0,2,0);
  e|=ttl_vector_combine_line_left(1,1,0,1,NULL,2,0,0,1);
  e|=ttl_vector_combine_line_left(1,1,1,1,NULL,2,0,2,0);
  
   return e;
}



int ttl_vector_combine_line_left(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
	
  return line_combine_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,combine_tiles,0);
}

 int test_combine_line_Right()
{
  int e=0;
  e|=ttl_vector_combine_line_Right(0,0,0,0,"Empty list is empty after combine line Right",0,0,0,0);
  e|=ttl_vector_combine_line_Right(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector_combine_line_Right(1,0,0,0,NULL,1,0,0,0);
  e|=ttl_vector_combine_line_Right(1,1,0,0,NULL,0,2,0,0);
  e|=ttl_vector_combine_line_Right(0,0,1,1,NULL,0,0,0,2);
  e|=ttl_vector_combine_line_Right(0,0,0,1,NULL,0,0,0,1);
  e|=ttl_vector_combine_line_Right(1,0,1,1,NULL,1,0,0,2);
  e|=ttl_vector_combine_line_Right(1,1,0,1,NULL,0,2,0,1);
  e|=ttl_vector_combine_line_Right(1,1,1,1,NULL,0,2,0,2);
  
   return e;
}



int ttl_vector_combine_line_Right(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
	
  return line_combine_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,combine_tiles,1);
}


 int test_board_read_column(){
 	
 	int e = 0;
   int board[16]=  {1, 0, 2, 0, 
                    0, 2, 2, 0, 
                    0, 0, 2, 0, 
                    1, 0, 2, 0};
   
   int column0[4] = {1, 0, 0, 1};
   e|= vector_board_read_column(board, 0, column0);
   
   int column1[4] = {0, 2, 0, 0};
   e|= vector_board_read_column(board, 1, column1);
   
   int column2[4] = {2, 2, 2, 2};
   e|= vector_board_read_column(board, 2, column2);
   
   
   int column3[4] = {0, 0, 0, 0};
    e|= vector_board_read_column(board, 3, column3);
   
   return e;
 	
 	
 	
 }
 
int vector_board_read_column(int in[16], int column, int out[4])
{
   int **board = calloc(4, sizeof(int *));
   int i = 0;
   int j = 0;
   for(i = 0; i < 4; ++i)
   {
      board[i] = calloc(4, sizeof(int));
      for(j = 0; j < 4; ++j)
      {
         int index = 4 * i + j;
         board[i][j] =  in[index];
      }
   }
   

   printf("Read column %d from {\n {%d,%d,%d,%d}\n {%d,%d,%d,%d}\n {%d,%d,%d,%d}\n {%d,%d,%d,%d}} \n yields {%d,%d,%d,%d} - ",
             column, 
             in[0], in[1], in[2], in[3], 
             in[4], in[5], in[6], in[7],
             in[8], in[9], in[10], in[11], 
             in[12], in[13], in[14], in[15],
             out[0], out[1], out[2], out[3]);
      
   fflush(stdout);
   int t[4] = {-1, -1, -1, -1};
   board_read_column(4, board, column, t);
    if (
          (out[0]!=t[0])||(out[1]!=t[1])||(out[2]!=t[2])|| (out[3]!=t[3]))
        {
	     printf("FAILED: Get column %d from {{%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}} returned {%d,%d,%d,%d} instead of"
                 " {%d,%d,%d,%d}\n",
                 column,
                 in[0], in[1], in[2], in[3], 
                 in[4], in[5], in[6], in[7],
                 in[8], in[9], in[10], in[11], 
                 in[12], in[13], in[14], in[15],
                 t[0], t[1], t[2], t[3], 
                 out[0], out[1], out[2], out[3]);
         
          return -1;
        } 
    
      printf("PASSED.\n");
      return 0;
    
}

 int test_board_set_column()
{
   int e = 0;
   int board[16]=  {0, 0, 2, 0, 
                    0, 0, 2, 0, 
                    0, 4, 0, 0, 
                    1, 0, 2, 0};
   
   int column0[4] = {1, 0, 0, 1};
   int out0[16] = {1, 0, 2, 0,
                   0, 0, 2, 0,
				   0, 4, 0, 0,
				   1, 0, 2, 0};
   e|= vector_board_set_column(board, 0, column0, out0);
   
   int column1[4] = {2, 0, 4, 0};
   int out1[16] = {0, 2, 2, 0,
                   0, 0, 2, 0,
				   0, 4, 0, 0,
				   1, 0, 2, 0};
   e|= vector_board_set_column(board, 1, column1, out1);
   
   int column2[4] = {2, 2, 8, 2};
   int out2[16] = {0, 0, 2, 0,
                   0, 0, 2, 0,
				   0, 4, 8, 0,
				   1, 0, 2, 0};
   e|= vector_board_set_column(board, 2, column2, out2);
   
   
   int column3[4] = {4, 4, 1, 0};
   int out3[16] = {0, 0, 2, 4,
                   0, 0, 2, 4,
				   0, 4, 0, 1,
				   1, 0, 2, 0};
   e|= vector_board_set_column(board, 3, column3, out3);
   
   return e;
}

 int vector_board_set_column(int in[16], int column, int columnData[4], int out[16])
{
   int **board = calloc(4, sizeof(int *));
   int i = 0;
   int j = 0;
   for(i = 0; i < 4; ++i)
   {
      board[i] = calloc(4, sizeof(int));
      for(j = 0; j < 4; ++j)
      {
         int index = 4 * i + j;
         board[i][j] =  in[index];
      }
   }
   

   printf("Set column %d to {%d,%d,%d,%d} for \n{{%d,%d,%d,%d}\n {%d,%d,%d,%d}\n {%d,%d,%d,%d}\n {%d,%d,%d,%d}}\n yields\n {{%d,%d,%d,%d}\n {%d,%d,%d,%d}\n {%d,%d,%d,%d}\n {%d,%d,%d,%d}} - ",
             column,
             columnData[0], columnData[1], columnData[2], columnData[3], 
             in[0], in[1], in[2], in[3], 
             in[4], in[5], in[6], in[7],
             in[8], in[9], in[10], in[11], 
             in[12], in[13], in[14], in[15],
             out[0], out[1], out[2], out[3], 
             out[4], out[5], out[6], out[7],
             out[8], out[9], out[10], out[11], 
             out[12], out[13], out[14], out[15]);
      
   fflush(stdout);
   board_set_column(4, board, column, columnData);
    if ((board[0][0]!=out[0])||(board[0][1]!=out[1])||(board[0][2]!=out[2])|| (board[0][3]!=out[3]) ||
          (board[1][0]!=out[4])||(board[1][1]!=out[5])||(board[1][2]!=out[6])|| (board[1][3]!=out[7]) ||
          (board[2][0]!=out[8])||(board[2][1]!=out[9])||(board[2][2]!=out[10])|| (board[2][3]!=out[11]) ||
          (board[3][0]!=out[12])||(board[3][1]!=out[13])||(board[3][2]!=out[14])|| (board[3][3]!=out[15]) )
        {
	     printf("FAILED: Set column %d to {%d,%d,%d,%d} for  {{%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}} returned {{%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}} instead of"
                 " {{%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}}\n",
                 column,
                 columnData[0], columnData[1], columnData[2], columnData[3], 
                 in[0], in[1], in[2], in[3], 
                 in[4], in[5], in[6], in[7],
                 in[8], in[9], in[10], in[11], 
                 in[12], in[13], in[14], in[15],
                 board[0][0], board[0][1], board[0][2], board[0][3],
                 board[1][0], board[1][1], board[1][2], board[1][3],
                 board[2][0], board[2][1], board[2][2], board[2][3],
                 board[3][0], board[3][1], board[3][2], board[3][3],
                 out[0], out[1], out[2], out[3], 
                 out[4], out[5], out[6], out[7],
                 out[8], out[9], out[10], out[11], 
                 out[12], out[13], out[14], out[15]);
           
          return -1;
        } 
         
      printf("PASSED.\n");
      return 0;
}
 
 
 
  int board_vector_test(int in[16], int out[16],int (*func)(int,int **))
{
   int **board = calloc(4, sizeof(int *));
   int i = 0;
   int j = 0;
   for(i = 0; i < 4; ++i)
   {
      board[i] = calloc(4, sizeof(int));
      for(j = 0; j < 4; ++j)
      {
         int index = 4 * i + j;
         board[i][j] =  in[index];
      }
   }
   
  
      printf("\n{{%d,%d,%d,%d}\n{%d,%d,%d,%d}\n{%d,%d,%d,%d}\n{%d,%d,%d,%d}}  \nafter yields\n {{%d,%d,%d,%d}\n {%d,%d,%d,%d}\n {%d,%d,%d,%d}\n {%d,%d,%d,%d}} - ",
              
             in[0], in[1], in[2], in[3], 
             in[4], in[5], in[6], in[7],
             in[8], in[9], in[10], in[11], 
             in[12], in[13], in[14], in[15],
             
             out[0], out[1], out[2], out[3], 
             out[4], out[5], out[6], out[7],
             out[8], out[9], out[10], out[11], 
             out[12], out[13], out[14], out[15]
            );
    
   fflush(stdout);
   func(4, board);
    if (
          (board[0][0]!=out[0])||(board[0][1]!=out[1])||(board[0][2]!=out[2])|| (board[0][3]!=out[3]) ||
          (board[1][0]!=out[4])||(board[1][1]!=out[5])||(board[1][2]!=out[6])|| (board[1][3]!=out[7]) ||
          (board[2][0]!=out[8])||(board[2][1]!=out[9])||(board[2][2]!=out[10])|| (board[2][3]!=out[11]) ||
          (board[3][0]!=out[12])||(board[3][1]!=out[13])||(board[3][2]!=out[14])|| (board[3][3]!=out[15]) )
        {
	     printf("FAILED: {{%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}} became {{%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}} instead of"
                 " {{%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}, {%d,%d,%d,%d}}\n",
                 in[0], in[1], in[2], in[3], 
                 in[4], in[5], in[6], in[7],
                 in[8], in[9], in[10], in[11], 
                 in[12], in[13], in[14], in[15],
                 board[0][0], board[0][1], board[0][2], board[0][3],
                 board[1][0], board[1][1], board[1][2], board[1][3],
                 board[2][0], board[2][1], board[2][2], board[2][3],
                 board[3][0], board[3][1], board[3][2], board[3][3],
                 out[0], out[1], out[2], out[3], 
                 out[4], out[5], out[6], out[7],
                 out[8], out[9], out[10], out[11], 
                 out[12], out[13], out[14], out[15]);
          
          return -1;
        } 
       
      printf("PASSED.\n");
      return 0;
    
}

  
int main(int argc,char **argv)
{
  int e=0;
  e|=test_shift_line_left();
  e|=test_shift_line_Right();
  e|=test_combine_line_left();
  e|=test_combine_line_Right();
  e|=test_tilt_left();
  e|=test_tilt_Right();
  e|=test_board_read_column();
  e|=test_board_set_column();
  return e;
}
