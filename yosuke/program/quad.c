#include <stdio.h>
#include <math.h>
int main(void){
  double a;
  double b;
  double c;
  double ans1;
  double ans2;
  printf("ax^2+bx+c=0\n");
  printf("a= ");
  scanf("%lf",&a);
  printf("b= ");
  scanf("%lf",&b);
  printf("c= ");
  scanf("%lf",&c);
  ans1=(-b+sqrt((pow(b,2)-4*a*c)))/2*a;
  ans2=(-b-sqrt((pow(b,2)-4*a*c)))/2*a;
  printf("x = %f, %f\n",ans1,ans2);
  return 0;
}
