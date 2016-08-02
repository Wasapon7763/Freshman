#include <stdio.h>
#define N 10

int factrial(int x);                    //階乗を計算する関数
int combination(int x, int y);      //Combinationを計算する関数

int main(void){
 
 	/* ここから編集（1） */
  int i,j;
  for (i=0;i<10;i++){
    for (j=0;j<=i;j++){
    }
  }

	/* ここまで編集（1） */
 
	return 0;
}


/* ここから編集（2） */
int factrial(int x){
  int a=1;
  while (x>0){
    a=a*x;
    x--;
  }
  return a;
}

/* ここまで編集（2） */
int combination(int x, int y){
}
