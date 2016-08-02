#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int Scores[15];
int Grade[15];
int main(void){
  srand((unsigned)time(NULL));
  double avg=0;
  int i;
  for (i=0;i<15;i++){
    int n=(int)(rand()/(RAND_MAX+1.0)*101);
    Scores[i]=n;
  }
  for (i=0;i<15;i++){
    int nn=Scores[i]/10+1;
    Grade[i]=nn;
  }
  printf("Before: ");
  for (i=0;i<15;i++){
    printf("%2d,",Scores[i]);
  }
  printf("\n After: ");
  for (i=0;i<15;i++){
    printf("%2d,",Grade[i]);
  }
  for (i=0;i<15;i++){
    avg=avg+Grade[i];
  }
  printf("\nAverage is %2.2f.\n",avg/15);
  return 0;
}
