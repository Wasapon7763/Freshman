#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void init(int **board);
void disp(int **board);
void solve(int **board);
int main(void){
  int i,j,k;
  int **board;
  if ((board=(int **)malloc(9*sizeof(int *)))==NULL){
    printf("memory error\n");
    exit(1);
  }
  for (i=0;i<9;i++){
    if ((board[i]=(int *)malloc(9*sizeof(int)))==NULL){
      printf("memory error\n");
    }
  }
  init(board);
  solve(board);
  return 0;
}
void init(int **board){
  int i,j,n;
  char str[9];
  for (i=0;i<9;i++){
    fgets(str, 11, stdin);
    for (j=0;j<9;j++){
      if (str[j]!=' '){
	n=(int)str[j]-(int)'0';
	board[i][j]=n;
      }
      else{
	board[i][j]=0;
      }
    }
  }
}
void disp(int **board){
  int i,j;
  for (i=0;i<9;i++){
    for (j=0;j<9;j++){
      printf("%3d",board[i][j]);
    }
    printf("\n");
  }
}
int checkava(int **board, int n, int x, int y){
  int i,j;
  for (i=0;i<9;i++)
    if (board[x][i]==n) return 0;
  for (i=0;i<9;i++) 
    if (board[i][y]==n) return 0;
  for (i=0;i<3;i++)
    for (j=0;j<3;j++)
      if (board[3*(x/3)+i][3*(y/3)+j]==n) return 0;
  if (x==y){
    for (i=0;i<9;i++)
      if (board[i][i]==n) return 0;
  }
  if (x+y==8){
    for (i=0;i<9;i++)
      if (board[i][8-i]==n) return 0;
  }
  return 1;
}
void solve(int **board){
  int i,j,x=-1,y=-1,ava=1;
  for (i=0;i<9;i++){
    for (j=0;j<9;j++){
      if (board[i][j]==0){
	x=i;
	y=j;
	break;
      }
    }
  }
  if (x==-1&&y==-1){
    disp(board);
    return;
  }
  for(ava=1;ava<10;ava++){
    if (checkava(board, ava, x, y)==1){
      board[x][y]=ava;
      solve(board);
      board[x][y]=0;
    }
  }
}
