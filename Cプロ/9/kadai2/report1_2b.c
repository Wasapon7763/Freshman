#include <stdio.h>
#include <stdlib.h>
int comb(int n, int r);
int perm(int n, int r);
int factorial(int n);
int main(void){
  int n,r;
  printf("input n and r(int int):");
  scanf("%d %d",&n,&r);
  if (n<r){
    printf("error n<r\n");
    exit(1);
  }
  printf("%dC%d=%d\n",n,r, comb(n,r));
  return 0;
}
int comb(int n, int r){
  int i=perm(n,r)/factorial(r);
  return i;
}
int perm(int n, int r){
  int i;
  int foo=1;
  for (i=0;i<r;i++){
    foo*=n;
    n--;
  }
  return foo;
}
int factorial(int n){
  int i=1;
  while (n>0){
    i*=n;
    n--;
  }
  return i;
}
