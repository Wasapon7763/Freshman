#include<stdio.h>
int main(void){
  int i=1,n,ans=0;
  printf("Input number N=: ");
  scanf("%d",&n);
  while(i<n+1){
    ans=ans+2*i-1;
    i++;
  }
  printf("Answer is %d.\n",ans);
  return 0;
}
