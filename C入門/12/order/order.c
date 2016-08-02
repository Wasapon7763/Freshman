#include <stdio.h>
void order(int *x,int *y){
  int c;
  c=*x;
  *x=*y;
  *y=c;
}
int main(void){
  int x=7, y=3;
  printf("x: adress = %p, value = %d, y: adress = %p, value = %d\n",&x,x,&y,y);
  order(&x,&y);
  printf("x: adress = %p, value = %d, y: adress = %p, value = %d\n",&x,x,&y,y);
  return 0;
}

