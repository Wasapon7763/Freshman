#include <stdio.h>
#include <stdlib.h>
int comb(int n, int r);
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
  if (n==r||r==0) 
    return 1;
  else
    return comb(n-1,r)+comb(n-1,r-1);
}
