#include <stdio.h>
int main(void){
  int a,b,c,mx;
  printf("Input nuber a: ");
  scanf("%d",&a);
  printf("Input nuber b: ");
  scanf("%d",&b);
  printf("Input nuber c: ");
  scanf("%d",&c);
  mx=a;
  if (mx<=b){
    mx=b;

  }
      if (mx<=c){
	mx=c;
      }
  printf("The greatest number is %d.\n",mx);
  return 0;
}
