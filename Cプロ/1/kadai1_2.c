#include <stdio.h>
#define N 4
void disp(int ans[N][N]){
  int i,j;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      printf("%-4d ",ans[i][j]);
    }
    printf("\n");
  }
}
int main(void){
  int a[N][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  int b[N][N]={{17,18,19,20},{21,22,23,24},{25,26,27,28},{29,30,31,32}};
  int ans[N][N];
  int i,j,l;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      int num=0;
      for (l=0;l<N;l++){
	num+=a[i][l]*b[l][j];
      }
      ans[i][j]=num;
    }
  }
  disp(ans);
  return 0;
}
