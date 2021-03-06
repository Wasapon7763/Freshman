#include <stdio.h>
#include <string.h>
#define N 4
void gauss(double a[][N+1],double b[]);
double mat1[N+1][N+1]={{0.0,0.0,0.0,0.0,0.0},{0.0,1.0,2.0,1.0,1.0},{0.0,4.0,5.0,-2.0,4.0},{0.0,4.0,3.0,-3.0,1.0},{0.0,2.0,1.0,1.0,3.0}};
double mat2[N+1]={0.0,-1.0,-7.0,-12.0,2.0};
int main(void){
  int i;
  gauss(mat1,mat2);
  printf("\nAnswer:\n");
  for (i=1;i<=N;i++) printf("%f ",mat2[i]);
  printf("\n");
  return 0;
}
void gauss(double a[][N+1],double b[]){
  int i,j,k,hoge;
  double d;
  for (i=1;i<=N-1;i++){
    for (j=i+1;j<=N;j++){
      d=(-1)*(a[j][i]/a[i][i]);
      for (k=0;k<=N;k++){
	a[j][k]+=d*a[i][k];
      }
      b[j]+=d*b[i];
      printf("%f ",b[j]);
    }
  }
  for (i=1;i<=N;i++){
    for (j=1;j<=N;j++){
      printf("%f ",a[i][j]);
    }
    printf("\n");
  }
  for (i=1;i<=N;i++) printf("%f ",mat2[i]);
  printf("\n");
  for (i=N;i>=1;i--){
    hoge=0;
    for (j=0;j<N-i;j++){
      hoge+=a[i][N-j]*b[N-j];
    }
    b[i]=(b[i]-hoge)/a[i][i];
  }
}
