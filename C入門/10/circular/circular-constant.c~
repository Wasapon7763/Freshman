#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main(void){
  int i;
  double x,y;
  int n,r;
  srand((unsigned)time(NULL));
  printf("How many trials? ");
  scanf("%d",&n);
  for (i=0;i<n;i++){
    x=(double)(rand()/(RAND_MAX+0.0));
    y=(double)(rand()/(RAND_MAX+0.0));
    if (sqrt(x*x+y*y)<1)
      r++;
  }
  //printf("The number of pair x and y that satisfies √(x^2+y^2)<1: %d\n",r);
  printf("The approximate value of pi: %f\n",((double)r/(double)n)*4);
  return 0;
}
