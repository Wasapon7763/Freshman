#include <stdio.h>
#include <time.h>
#include <math.h>
int main(void){
  int i,n;
  clock_t start, end;
  start=clock();
  //printf("Input an integer:");
  //scanf("%d",&n);
  for (n=1;n<200;n++){
    for (i=3;i<(int)sqrt(n);i+=2){
      if (n%i==0||n%2==0||sqrt(n)-(int)sqrt(n)==0){
	//printf("not prime\n");
	break;
      }
    }
    if ((i>=(int)sqrt(n)||n==2)&&n!=1)
      printf("%d ",n);
    //printf("prime\n");
    else if(n==1)
      printf("%d ",n);
    //printf("not prime\n");
  }
  end=clock();
  printf("%d",end-start);
  return 0;
}
