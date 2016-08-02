#include<stdio.h>

#define N 10

int main(void){
	int i,j;
	int pascal[N][N];

	/* ここから編集 */
	for (i=0;i<10;i++){
	  for (j=0;j<=i;j++){
	    pascal[i][j]=1;
	  }
	}
	for (i=2;i<10;i++){
	  for (j=1;j<i;j++){
	    pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
	  }
	}
	for (i=0;i<10;i++){
	  for (j=0;j<=i;j++){
	    printf("%d ",pascal[i][j]);
	  }
	  printf("\n");
	}

	/* ここまで編集 */

	return 0;
}
