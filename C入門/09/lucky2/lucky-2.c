#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
  int n;
  int l[3]={0,0,0};
  double result[3];
  srand((unsigned)time(NULL));
  for (int i=0;i<1000000;i++){
    n=(int)(rand()/(RAND_MAX+1.0)*10);
    if (n==0)//not lucky
      l[0]++;
    else if (n>0 && n<7)//lucky
      l[1]++;
    else//very lucky
      l[2]++;
  }
  for (int i=0;i<3;i++){
    result[i]=((double)l[i]/1000000)*100;
  }
  printf("Very Lucky : %f %\n",result[2]);
  printf("Lucky : %f %\n",result[1]);
  printf("Not Lucky : %f %\n ",result[0]);
  return 0;
}
