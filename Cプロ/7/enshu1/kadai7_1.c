#include <stdio.h>
void euler(double x, double y, double a, double b, int n);
double f(double x, double y);
int main(void){
  int n;
  double a=0.0,b=1.0,x=0.0,y=1.0;
  printf("Please input n:");
  scanf("%d",&n);
  euler(x, y, a, b ,n);
  return 0;
}
void euler(double x, double y, double a, double b, int n){
  double h;
  int i;
  h=(b-a)/n;
  for (i=1;i<=n;i++){
    printf("x=%f, y=%f\n",x,y);
    y=y+h*f(x,y);
    x=a+i*h;
  }


}
double f(double x, double y){
  return x+y;
}
