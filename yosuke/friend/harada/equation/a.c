#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//行列を出力
void disp(double **a,double *b,int N){
  int i,j;
  printf("A,b=\n");
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      printf("%7.2f ",a[i][j]);
    }
    printf("| %6.2f\n",b[i]);
  }
}
//ガウスの消去法
void gdeletion(double **a, double *b,int N){
  int i,j,k;
  double r;
  //前進消去
  for (k=0;k<N-1;k++){
    disp(a,b,N);
    for (i=k+1;i<N;i++){
      r=a[i][k]/a[k][k];
      for (j=k;j<N;j++){
	a[i][j]-=a[k][j]*r;
      }
      b[i]-=b[k]*r;
    }
  }
  //後退代入
  for (i=N-1;i>=0;i--){
    disp(a,b,N);
    for (j=i+1;j<N;j++){
      b[i]-=a[i][j]*b[j];
    }
    b[i]/=a[i][i];
  }
  disp(a,b,N);
}
int main(void){
  int N,i,j;
  double **a,*b;
  printf("N=");
  scanf("%d",&N);
  //メモリの確保
  a=(double **)malloc(sizeof(double *)*(N+1));
  if (a==NULL){
    printf("error");
    exit(1);
  }
  for (i=0;i<N;i++){
    a[i]=(double *)malloc(sizeof(double)*(N+1));
    if (a[i]==NULL){
      printf("error");
      exit(1);
    }
  }
  b=(double *)malloc(sizeof(double *)*(N+1));
  if (b==NULL){
    printf("error");
    exit(1);
  }
  //数値代入
  double d;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      printf("A[%d][%d]=",i,j);
      scanf("%lf",&d);
      a[i][j]=d;
    }
  }
  for (i=0;i<N;i++){
    printf("b[%d]=",i);
    scanf("%lf",&d);
    b[i]=d;
  }
  //計算
  gdeletion(a,b,N);
  return 0;
}
