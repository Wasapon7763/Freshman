#include <stdio.h>
#include <stdlib.h>
void init(int *a, int *b, int n, int r);
void simp(int *a, int *b, int r);
void show(int *a, int *b, int r, int c);
int main(void){
  int n=65,r,i;
  int *ar1,*ar2;
  for (i=40;i<=50;i++){
    if (n-i<i)
      r=n-i;
    else 
      r=i;
    ar1=(int *)malloc(sizeof(int)*r);
    ar2=(int *)malloc(sizeof(int)*r);
    if (ar1==NULL||ar2==NULL){   
      printf("error\n");
      exit(1);
    }
    init(ar1,ar2,n,r);
    simp(ar1,ar2,r);
    show(ar1,ar2,r,i);
  }
  return 0;
}
void init(int *a, int *b,int n, int r){
  int i;
  for (i=0;i<r;i++){
    a[i]=i+1;
    b[i]=n-r+1+i;
  }
}
void simp(int *a, int *b, int r){
  int l,i,k;
  int boo1,boo2;
  int n=a[r-1];
  for (l=2;l<=n;l++){
    while (1){
      boo1=-1;
      boo2=-2;
      for (i=0;i<n;i++){
	if (a[i]%l==0){
	  boo1=i;
	  break;
	}
      }
      for (k=0;k<n&&boo1!=-1;k++){
	if (b[k]%l==0){
	  boo2=k;
	  break;
	}
      }
      if (boo1!=-1&&boo2!=-1){
	a[boo1]/=l;
	b[boo2]/=l;
      }
      if (boo1==-1)
	break;
    }
  }
}
void show(int *a, int *b, int r,int c){
  int i;
  long n=1l,nn=1l;
  for (i=0;i<r;i++){
    n*=a[i];
  }
  for (i=0;i<r;i++){
    nn*=b[i];
  }
  printf("65C%d=%ld\n",c,nn/n);
}
