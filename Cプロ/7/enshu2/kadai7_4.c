#include <stdio.h>
double kaijou(int n){
  double i=1;
  while (n>0){
    i*=n;
    n--;
  }
  return i;
}
int main(void){
  int i,n;
  double e=1;
  for (i=1;i<=20;i++){
    e+=1/kaijou(i);
  }
  printf("e=%.15f\n",e);

  return 0;
}
