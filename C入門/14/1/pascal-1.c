#include <stdio.h>
#define N 10
int main(void){
  int i,j;
  int pascal[10][10];
  for (i=0;i<10;i++){
    for (j=0;j<10;j++){
      pascal[i][j]=1;
    }
  }
  for (i=2;i<10;i++){
    for (j=1;j<i;j++){
      pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];

    }
  }
  int space=30;
  int c=1;
  for (i=0;i<10;i++){
    for (j=0;j<c;j++){
      if (j==0)
	printf("%*d",space,pascal[i][j]);
      else
	printf("%5d ",pascal[i][j]);
    }
    printf("\n");
    space=space-3;
    c++;
  }
  return 0;
}
