#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
  int n;
  srand((unsigned)time(NULL));
  n=(int)(rand()/(RAND_MAX+1.0)*10);
  if (n==0)
    printf("Not Lucky\n");
  else if (n>0 && n<7)
    printf("Lucky\n");
  else
    printf("Very Lucky\n");
  return 0;
}
