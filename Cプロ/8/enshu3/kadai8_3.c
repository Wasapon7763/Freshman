#include <stdio.h>
#include <math.h>
int gcd(int x, int y){
  if (y==0) return x;
  int n;
  while (y!=0){
    n=x;
    x=y;
    y=n%y;
  }
  return x;
}
int main(void){
  int n1,n2;
  printf("Inpute first integer: ");
  scanf("%d",&n1);
  printf("Input second integer: ");
  scanf("%d",&n2);
  printf("gcd(%d, %d) = %d\n",n1,n2,gcd(n1,n2));
  return 0;
}
