#include <stdio.h>
void rk(double x, double y, double a, double b, int n);
double f(double x, double y);
int main(void){
  int n;
  double a=0.0,b=1.0,x=0.0,y=1.0;
  printf("Please input n:");
  scanf("%d", &n);
  rk(x, y, a, b, n);
  return 0;
}
void rk(double x, double y, double a, double b, int n){
  double k1,k2,k3,k4,h;
  int i;
  h=(b-a)/n;
  for (i=1;i<=n;i++){
    printf("x=%f, y=%f\n",x,y);
    k1=f(x,y);
    k2=f(x+0.5*h,y+0.5*h*k1);
    k3=f(x+0.5*h,y+0.5*h*k2);
    k4=f(x+h,y+h*k3);
    y=y+(h/6)*(k1+2*k2+2*k3+k4);
    x=a+i*h;
  }
}
double f(double x, double y){
  return x+y;
}
