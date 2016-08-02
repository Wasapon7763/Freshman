#include <stdio.h>
#include <stdlib.h>
void solve(double **a, double *b);
void init(int **cir, double **mat1, double *mat2);
void disp(int **a);
int n,m,count=0;
int main(void){
  int i,j,num=0,foo;
  int **cir;
  double **mat1, *mat2;
  scanf("%d",&n);
  scanf("%d",&m);
  if ((cir=(int **)malloc(sizeof(int *)*n))==NULL){
    printf("memory error");
    exit(1);
  }
  for (i=0;i<n;i++){
    if ((cir[i]=(int *)malloc(sizeof(int)*m))==NULL){
      printf("memory error");
      exit(1);
    }
  }
  for (i=0;i<n;i++){
    for (j=0;j<m;j++){
      scanf("%d",&foo);
      cir[i][j]=foo;
    }
  }
  for (i=0;i<n;i++){
    for (j=0;j<m;j++){
      if (cir[i][j]>0)
	count++;
    }
  }
  if ((mat1=(double **)malloc(sizeof(double *)*count))==NULL){
    printf("memory error");
    exit(1);
  }
  for (i=0;i<count;i++){
    if ((mat1[i]=(double *)malloc(sizeof(double)*count))==NULL){
      printf("memory error");
      exit(1);
    }
  }
  if ((mat2=(double *)malloc(sizeof(double)*count))==NULL){
    printf("memory error");
    exit(1);
  }
  printf("\nCircuit:\n");
  for (i=0;i<n;i++){
    for (j=0;j<m;j++){
      printf("%2d ",cir[i][j]);
    }
    printf("\n");
  }
  printf("\nNumbered grids:\n");
  init(cir, mat1, mat2);
  solve(mat1,mat2);
  printf("\n n   Potential\n");
  for (i=0;i<count;i++) printf("%3d %9.5f\n",i,mat2[i]);
  return 0;
}
void init(int **cir, double **mat1, double *mat2){
  int i,j,k;
  int coo[n+2][m+2];
  count=0;
  for (i=0;i<n;i++){
    for (j=0;j<m;j++){
      if (cir[i][j]>0){
	coo[i+1][j+1]=count;
	count++;
      }
      else{
	coo[i+1][j+1]=-1;
      }
    }
  }
  for (i=0;i<m+2;i++){
    coo[0][i]=-1;
    coo[n+1][i]=-1;
  }
  for (i=0;i<n+2;i++){
    coo[i][0]=-1;
    coo[i][m+1]=-1;
  }
  for (i=0;i<count;i++){
    for (j=0;j<count;j++){
      mat1[i][j]=0;
    }
    mat2[i]=0;
  }
  for (i=0;i<n;i++){
    for (j=0;j<m;j++){
      if (cir[i][j]==0) continue;
      else{
	double grids=0;
	int place=coo[i+1][j+1];
	if (coo[i+2][j+1]!=-1&&cir[i][j]==1){
	  grids++;
	  mat1[place][coo[i+2][j+1]]=-1;
	}
	if (coo[i][j+1]!=-1&&cir[i][j]==1){
	  grids++;
	  mat1[place][coo[i][j+1]]=-1;
	}
	if (coo[i+1][j+2]!=-1&&cir[i][j]==1){ 
	  grids++;
	  mat1[place][coo[i+1][j+2]]=-1;
	}
	if (coo[i+1][j]!=-1&&cir[i][j]==1){
	  mat1[place][coo[i+1][j]]=-1;
	  grids++;
	}
	if (cir[i][j]==2){
	  grids=1;
	  mat2[place]=5;
	}
	else{
	  mat2[place]=0;
	}
	if (cir[i][j]==3) grids++;
	mat1[place][place]=grids;
      }
    }
  }
  for (i=1;i<n+1;i++){
    for (j=1;j<m+1;j++){
      if (coo[i][j]!=-1)
	printf("%2d ",coo[i][j]);
      else
	printf("   ");
    }
    printf("\n");
  }
}
void solve(double **a, double *b){
  int i,j,k;
  double d,hoge;
  for (i=0;i<count-1;i++){
    for (j=i+1;j<count;j++){
      d=(-1)*(a[j][i]/a[i][i]);
      for (k=0;k<count;k++){
	a[j][k]+=d*a[i][k];
      }
      b[j]+=d*b[i];
    }
  }
  for (i=count-1;i>=0;i--){
    hoge=0;
    for (j=0;j<count-i-1;j++){
      hoge+=a[i][count-j-1]*b[count-j-1];
    }
    b[i]=(b[i]-hoge)/a[i][i];
  }
}
