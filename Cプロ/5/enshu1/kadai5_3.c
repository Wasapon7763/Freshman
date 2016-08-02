#include <stdio.h>
#include <math.h>

double bisec(double a, double b, double eps);
double f(double x);

int main(void){
  double a,b,x,y,eps;

  eps=pow(2.0, -30.0);
  a=0.0; b=1.0;

  printf("answer = %f\n", bisec(a,b,eps));
  
  return 0;
}
double bisec(double a, double b, double eps){
  while (fabs(a-b)>eps){
    double n=0.5*(a+b);
    if (f(a)*f(n)<0) b=n;
    else if (f(a)*f(n)>0) a=n;
  }
  return (a+b)/2;
}

double f(double x){
  return(pow(x,3)-3*x+1);
}
