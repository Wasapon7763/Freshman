#include <stdio.h>
#include <stdlib.h>
typedef struct{
  char* function;
  int num;
  double* x;
  double* y;
} Points;
double f(double x){
  return x*x;
}
void init(Points* points, char* function, int num){
  points->function=function;
  points->num=num;
  points->x=(double*)malloc(sizeof(double)*num);
  points->y=(double*)malloc(sizeof(double)*num);
}
void getpoints(Points* points, int num, double* x, double* y){
  int i;
  for (i=0;i<num;i++){
    points->x[i]=i;
    points->y[i]=f(i+0.0);
  }
}
void show(Points points){
  printf("%s\n",points.function);
  int i;
  printf("x ");
  for (i=0;i<points.num;i++){
    printf("%.1f",points.x[i]);
  }
  printf("\ny ");
  for (i=0;i<points.num;i++){
    printf("%.1f",points.y[i]);
  }
}

int main(void){
  Points p;
  int i=5;
  char* f="y=x^2";
  init(&p, f, i);
  getpoints(&p,p.num, p.x, p.y);
  show(p);
  return 0;
}
