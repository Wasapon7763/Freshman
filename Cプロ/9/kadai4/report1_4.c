#include <stdio.h>
#include <math.h>
int main(void){
  int n,i;
  int boo=1;
  printf("Input an integer:");
  scanf("%d",&n);
  if (n%2==0||sqrt(n)-(int)sqrt(n)==0){
    boo=0;
  }
  for (i=1;i<=(int)sqrt(n)&&boo==1;i++){
    if (n%i==0&&i!=1){
      boo=0;
      break;
    }
  }
  if (boo==0){
    printf("not prime\n");
  }
  if(boo==1||n==2){
    printf("prime\n");
  }
  return 0;
}
