#include <stdio.h>
#include <math.h>
#define num 21
int main(void){
  int i;
  int sqr[num],cb[num];
  for (i=0;i<num;i++){
    sqr[i]=i*i;
    cb[i]=i*i*i;
  }
  printf("number  square    cube\n");
  for (i=0;i<num;i++){
    printf("%5d   %5d   %5d\n",i,sqr[i],cb[i]);
  }
  return 0;
}
