#include <stdio.h>
#include <math.h>
void max(double *x, double *y){
  if (*x<*y)
    *x=*y;
}
void mn(double *x, double *y){
  if (*x>*y)
    *x=*y;
}
int main(void){
  double d,mx,min,dd;
  printf("Input x: ");
  scanf("%lf",&d);
  mx=d;
  min=d;
  dd=-d;
  max(&mx,&dd);
  mn(&min,&dd);
  dd=d*d;
  max(&mx,&dd);
  mn(&min,&dd);
  dd=sqrt(fabs(d));
  max(&mx,&dd);
  mn(&min,&dd);
  printf("Max is %f, Min is %f\n",mx,min);
  return 0;
}
