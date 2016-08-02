#include <stdio.h>
int main(void){
  int i,j,count;
  printf("Enter a number: ");
  scanf("%d",&i);
  for (j=2;j<i;j++){
    if(i%j==0){
      count++;
    }
  }
  if (count==0){
    printf("prime\n");  
  }
  else {
    printf("not prime\n");
    }
  return 0;
}
