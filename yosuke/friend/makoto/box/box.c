#include <stdio.h>
int findx(int board[5][5]){
  int i,j;
  for (i=0;i<5;i++){
    for (j=0;j<5;j++){
      if (board[i][j]==0){
	return i;
	break;
      }
    }
  }
  return -1;
}
int findy(int board[5][5]){
  int i,j;
  for (i=0;i<5;i++){
    for (j=0;j<5;j++){
      if (board[i][j]==0){
	return j;
	break;
      }
    }
  }
}
void disp(int board[5][5]){
  int i,j;
  for (i=0;i<5;i++){
    for (j=0;j<5;j++){
      printf("%d ",board[i][j]);
    }
    printf("\n");
  }
}
int main(void){
  int board[5][5]={0};
  int i,j,k;
  for (i=0;i<5;i++){
    int a,b,x,y;
    scanf("%d %d",&a,&b);
    x=findx(board);
    y=findy(board);
    for (j=x;j<x+b&&j<5;j++){
      for (k=y;k<y+b&&k<5;k++){
	board[j][k]=a;
      }
    }
  }
  disp(board);
  return 0;
}
