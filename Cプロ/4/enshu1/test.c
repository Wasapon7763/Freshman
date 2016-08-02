#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void baka(double **a,double *b,int N);
int main(int argc,char *argv[]){
  double **mat1,*mat2;
  FILE *fp;
  int i,j,N;
  if ((fp=fopen(argv[1],"r"))==NULL){
    printf("error");
    exit(1);
  }
  fscanf(fp,"%d",&N);

  if ((mat1=(double **)malloc((N+1)*sizeof(double *)))==NULL){
    printf("out of memory\n");
    exit(1);
    }
  /*mat1=malloc(sizeof(double **)*(N+1));
  for (i=1;i<=N;i++)
  mat1[i]=malloc(sizeof(double *)*(N+1));*/

  double d;
  for (i=1;i<=N;i++){
    for (j=1;j<=N;j++){
      fscanf(fp,"%lf",&d);
      mat1[i][j]=d;
      printf("%f",mat1[i][j]);
    }
  }
  fclose(fp); 
  return 0;
}
