#include <stdio.h>
#define num 20
int main(void){
  int score[num],j,mx=0;
  for (j=0;j<num;j++){
    score[j]=(j*83+11)%101;
  }
  for (j=0;j<num;j++){
    if(mx<=score[j]){
      mx=score[j];
    }
  }
  for (j=0;j<num;j++){
    printf("%d, ",score[j]);
  }
  printf("\nHighest score is %d.\n",mx);
  return 0;
}
