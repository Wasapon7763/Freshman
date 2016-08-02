#include <stdio.h>
#include <stdlib.h>
int fib(int n){
  if (n==0) return 0;
  else if(n==1) return 1;
  int boo=0;
  if (n<0){
    n*=(-1);
    boo=1;
  }
  int i,f,f1=0,f2=1;
  for (i=0;i<=n-1;i++){
    f=f1+f2;
    f2=f1;
    f1=f;
  }
  if (boo==1&&n%2==0)    return f*(-1);
  else return f;
}
int main(void){
  int n;
  printf("Input n to calculate nth fibonacci number(-40<=n<=40): ");
  scanf("%d",&n);
  if (n>40||n<-40){
    printf("Out of range\n");
    exit(1);
  }
  int i;
  printf("F(%d)=%d\n",n,fib(n));
  return 0;
}
