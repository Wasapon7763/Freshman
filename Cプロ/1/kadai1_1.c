#include <stdio.h>
int main(void){
  int n,m;
  printf("input two integers\n");
  printf("first one>> ");
  scanf("%d",&n);
  printf("second one>> ");
  scanf("%d",&m);
  printf("addition: %d\nsubtraction: %d\nmultiplication: %d\ndivision: %f\n",n+m,n-m,n*m,(n+0.0)/m);
  return 0;
}
