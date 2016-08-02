#include <stdio.h>
int main(void){
  int a;
  int b;
  int c;
  int sum;
  double avg;
  printf("Input three integers:\n");
  printf("a: ");
  scanf("%d",&a);
  printf("b: ");
  scanf("%d",&b);
  printf("c: ");
  scanf("%d",&c);
  sum=a+b+c;
  double d=sum;
  avg=d/3;
  printf("Sum is %d, Average is %2.1f.\n",sum,avg);
  return 0;
}
