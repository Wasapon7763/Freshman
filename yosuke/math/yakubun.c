#include <stdio.h>
#include <stdlib.h>
void init(int *a, int *b, int n, int r);
void simp(int *a, int *b, int r);
void show(int *a, int *b, int r);
int main(void){
  int n,r;
  int *ar1,*ar2;
  printf("Input n r:");
  scanf("%d %d",&n,&r);
  ar1=(int *)malloc(sizeof(int)*r);
  ar2=(int *)malloc(sizeof(int)*r);
  if (ar1==NULL||ar2==NULL){   
    printf("error\n");
    exit(1);
  }
  init(ar1,ar2,n,r);
  show(ar1,ar2,r);
  simp(ar1,ar2,r);
  show(ar1,ar2,r);
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
void show(int *a, int *b, int r){
  int i;
  long n=1,nn=1;
  printf("\n");
  for (i=0;i<r;i++){
    printf("%d ",a[i]);
    n*=a[i];
  }
  printf("\n");
  for (i=0;i<r;i++){
    printf("%d ",b[i]);
    nn*=b[i];
  }
  printf("\n%ld\n",nn/n);
}
