#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main(void){
  int i,j,n;
  int num[4]={10};
  int in;
  int input[4];
  int hit,blow,count=0;
  srand((unsigned)time(NULL));
  getrandom(num);
  while (1){
    hit=0;
    blow=0;
    scanf("%d",&in);
    for (i=0;i<4;i++){
      if (in/100<10&&i==0){
	input[0]=0;
	continue;
      }
      double d=floor(in/pow(10,3-i));
      input[i]=(int)d;
      in=in-input[i]*pow(10,3-i);
    }
    //printf("%d %d %d %d\n",num[0],num[1],num[2],num[3]);
    //printf("%d %d %d %d\n",input[0],input[1],input[2],input[3]);
    for(i=0;i<4;i++){
      for (j=0;j<4;j++){
	if (num[i]==input[j]){
	  if (i==j)
	    hit++;
	  else
	    blow++;
	  break;
	}
      }
    }
    if (hit==4){
      printf("Correct!\n");
      printf("Count: %d\n",count);
      printf("Good job!\n");
      break;
    }
    printf("hit>> %d\nblow>> %d\n",hit,blow);
    count++;
  }
}
int getrandom(int num[4]){
  int i,j,b;
  for (i=0;i<4;i++){ 
    int n=(int)(rand()/(RAND_MAX+1.0)*10);
    b=1;
    for (j=0;j<4;j++){
      if (num[j]==n){
	i--;
	b=0;
	break;
      }
    }
    if (b==1)
      num[i]=n;
  }  
  return num[4];
}
