#include <stdio.h>
void swap(int *a, int *b){
  int i;
  i=*a;
  *a=*b;
  *b=i;
}
int main(void){
  int x=100, y=200;
  printf("x=%d, y=%d\n", x, y);
  swap(&x, &y);
  printf("Swap: x=%d, y=%d\n", x, y);
  return 0;
}
