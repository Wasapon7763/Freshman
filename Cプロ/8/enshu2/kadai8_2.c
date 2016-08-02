#include <stdio.h>
int gcd(int x, int y){
  if (y==0) return x;
  else
    return gcd(y, x%y);
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
