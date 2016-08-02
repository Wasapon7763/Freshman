#include <stdio.h>
#include <math.h>
double max(double a, double b);
int main(void){
  double x,mx;
  printf("Input x: ");
  scanf("%lf",&x);
  mx=x;
  mx=max(mx,-x);
  mx=max(mx,x*x);
  mx=max(mx,sqrt(fabs(x)));
  printf("Answer is %f.\n",mx);
  return 0;
}
double max(double a, double b){
  if (a<b)
    return b;
  else
    return a;
}
