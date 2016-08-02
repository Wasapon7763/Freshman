#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main(void){
  int i,j;
  double x,y;
  int n,r=0;
  srand((unsigned)time(NULL));
  printf("How many trials? ");
  scanf("%d",&n);
  for (i=0;i<n;i++){
    x=(double)(rand()/(RAND_MAX+0.0));
    y=(double)(rand()/(RAND_MAX+0.0));
    if (y<sin(M_PI*x))
      r++;
  }
  double d=(double)r/(double)n;
  printf("Result is %lf(Error: %f)\n",d,d-2/M_PI);
  return 0;
}
