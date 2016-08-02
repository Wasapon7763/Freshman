#include<stdio.h>

#define N 10

/* 必要ならばここから関数を書いて良い */
int a(int n){
  int a=1;
  while (n>0){
    a=a*n;
    n--;
  }
  return a;
}

/* 必要ならばここまで関数を書いて良い */

int main(void){
	int i,j;
	int pascal[N*(N+1)/2];

	/* ここから編集 */
	int n=0;
	for (i=0;i<10;i++){
	  for (j=0;j<=i;j++){
	    pascal[n]=a(i)/(a(i-j)*a(j));
	    n++;
	  }
	}
	n=0;
	for (i=0;i<10;i++){
	  for (j=0;j<=i;j++){
	    printf("%d ",pascal[n]);
	    n++;
	  }
	  printf("\n");
	}

	/* ここまで編集 */

	return 0;
}
