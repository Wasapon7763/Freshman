#include <stdio.h>
#define N 10

int factrial(int x);                    //�K����v�Z����֐�
int combination(int x, int y);      //Combination���v�Z����֐�

int main(void){
 
 	/* ��������ҏW�i1�j */
  int i,j;
  for (i=0;i<10;i++){
    for (j=0;j<=i;j++){
    }
  }

	/* �����܂ŕҏW�i1�j */
 
	return 0;
}


/* ��������ҏW�i2�j */
int factrial(int x){
  int a=1;
  while (x>0){
    a=a*x;
    x--;
  }
  return a;
}

/* �����܂ŕҏW�i2�j */
int combination(int x, int y){
}
