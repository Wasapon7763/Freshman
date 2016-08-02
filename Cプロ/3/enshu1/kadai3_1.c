#include <stdio.h>
#include <string.h>
#define N 4
void gauss(double a[][N+1], double b[]);
double mat1[N+1][N+1]={{0.0, 0.0, 0.0, 0.0, 0.0},{0.0, 1.0, 2.0, 1.0, 1.0},{0.0, 4.0, 5.0, -2.0, 4.0},{0.0, 4.0, 3.0, -3.0, 1.0},{0.0, 2.0, 1.0, 1.0, 3.0}};
double mat2[N+1]={0.0, -1.0, -7.0, -12.0, 2.0}; 
int main(void){
  int i;
  gauss(mat1, mat2);
  printf("\nAnswer:\n");
  for (i=1; i<=N; i++)
    printf("%f ", mat2[i]);
  printf("\n");
  return 0;
}
void gauss(double a[][N+1], double b[]){
  int i, j, k;
  double alpha, tmp;
  int sz=sizeof(mat2)/sizeof(double)-1;
  for (k=1; k<=N; k++){
    for (i=k+1 ;i<=sz; i++){ //縦
      if (a[k][k]==0)
	continue;
      alpha=-(a[i][k]/a[k][k]);
      a[i][k]=0;
      for (j=k+1 ;j<=N; j++){ //引く
	a[i][j]=a[i][j]+alpha*a[k][j];
      }
      b[i]=b[i]+alpha*b[k];
    }
  }
  for (i=sz; i>=1; i--){
    tmp=0;
    for (j=0; j<4-i; j++){  //answer
      tmp+=a[i][sz-j]*b[sz-j];
    }
    b[i]=(b[i]-tmp)/a[i][i];
  }
}

