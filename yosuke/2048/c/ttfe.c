#include <stdio.h>
#define N 4
int main(void){
  int board[N][N]={{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
  int command=0;
  disp(board);
  scanf("%d",&command);
  if (command==1)
    left(board);
  if (command==2)
    right(board);
  if (command==3)
    down(board);
  if (command==4)
    up(board);
  disp(board);
  return 0;
}
int disp(int i[N][N]){
  int j,k;
  for (j=0;j<N;j++){
    for (k=0;k<N;k++){
      printf("     %d",i[j][k]);
    }
    printf("\n\n");
  }
}
int left(int i[N][N]){
  int j,k,l,min,m;
  for (j=0;j<4;j++){
    //for (m=0;m<3;m++){
      for (k=0;k<4;k++){
	if (i[j][k]==0){
	  min=k;
	  printf("\nmin:%d j:%d\n",min,j);
	  break;
	}
      }
      for (l=min;l<4;l++){
	i[j][l]=i[j][l+1];
	i[j][l+1]=0;
      }
      // }
  }
}
int right(int i[N][N]){
  int j,k,l,min;
  for (j=0;j<4;j++){
    for (k=0;k<4;k++){
      if (i[j][k]==0){
	min=k;
	printf("\nmin:%d j:%d\n",min,j);
	break;
      }
    }
    for (k=0;k<3;k++){
      for (l=min;l<3;l++){
	i[j][l]=i[j][l+1];
	i[j][l+1]=0;
      }
      min++;
    }
  }
}
int down(int i[N][N]){
  int j,k,l,min;
  for (j=0;j<4;j++){
    for (k=0;k<4;k++){
      if (i[j][k]==0){
	min=k;
	printf("\nmin:%d\n",min);
	break;
      }
    }
    for (k=0;k<3;k++){
      for (l=min;l<3;l++){
	i[j][l]=i[j][l+1];
	i[j][l+1]=0;
      }
      min++;
    }
  }
}
int up(int i[N][N]){
  int j,k,l,min;
  for (j=0;j<4;j++){
    for (k=0;k<4;k++){
      if (i[j][k]==0){
	min=k;
	printf("\nmin:%d\n",min);
	break;
      }
    }
    for (k=0;k<3;k++){
      for (l=min;l<3;l++){
	i[j][l]=i[j][l+1];
	i[j][l+1]=0;
      }
      min++;
    }
  }
}

