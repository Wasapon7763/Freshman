#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
  int n;
  int i=0;
  int result[6]={0,0,0,0,0,0};
  srand((unsigned)time(NULL));
  for  (int i=0;i<6000000;i++){
    n=(int)(rand()/(RAND_MAX+0.0)*6.0);
    result[n]++;
  }
  for (int j=0;j<6;j++){
    printf("Number of %d : %d\n",j+1,result[j]);
  }
  return 0;
}
