#include <stdio.h>
int main(void){
  int min,max,ii;
  printf("Enter min: ");
  scanf("%d",&min);
  printf("Enter max: ");
  scanf("%d",&max);
  for (ii=min;ii<=max;ii++){
    prime(ii);
  }
  return 0;
}
int prime(int i){
  int j;
  int count=0;
  if (i%2!=0)
    {
      for (j=1;j<=i/2;j++){
	if (count==2) {
	  break;
	  }
	if(i%j==0){
	  count++;
	}
      }
      if (count==1){
	printf("%d is prime\n",i);  
      }
    }
  return 0;
}
