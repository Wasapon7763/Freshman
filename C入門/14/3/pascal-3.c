#include <stdio.h>
int a(int n){
  int a=1;
  while (n>0){
    a=a*n;
    n--;
  }
  return a;
}
int main(void){
  int i,j;
  for (i=0;i<10;i++){
    printf("%*d",30-3*i,1);
    for (j=1;j<=i;j++){
      printf("%6d",a(i)/(a(i-j)*a(j)));
    }
    printf("\n");
  }
  return 0;
}
