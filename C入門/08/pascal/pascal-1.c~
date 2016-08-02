#include <stdio.h>
#define N 10
int main(void){
  int n,i;
  int space=30;
  int p[N][N];
  for (n=0;n<10;n++){
    for (i=0;i<=n;i++){
      p[n][i]=kaijou(n)/(kaijou(n-i)*kaijou(i));
    }
  }
  for (n=0;n<10;n++){
    for (i=0;i<=n;i++){
      if (i==0)
	printf("%*d",space,p[n][i]);
      else
	printf("%6d",p[n][i]);
    }
    space=space-3;
    printf("\n");
  }
  return 0;
}
int kaijou(int i){
  int j;
  int a=1;
  if (i==0)
    a=1;
  else{
    for (j=1;j<=i;j++){
      a=a*j;
    }
  }
  return a;
}
