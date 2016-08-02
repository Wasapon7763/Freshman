#include <stdio.h>
#include <math.h>
#define MAX 10
void newton(double x, double eps);
double f(double x);
double df(double x);
int main(void){
  double x;
  double eps=pow(2,-30.0);
  printf("Please input x0;");
  scanf("%lf", &x);
  newton(x,eps);
  return 0;
}
void newton(double x, double eps){
  double dx,q;
  int i=1;
  do{
    q=x;
    dx=-f(q)/df(q);
    x=q+dx;
    i++;
  }while(dx>=eps||i<MAX);
  printf("%f\n",x);
}
double f(double x){
  double d=pow(x,3.0)-2*x-5;
  return d;
}
double df(double x){
  double d=3*x*x-2;
  return d;
}
