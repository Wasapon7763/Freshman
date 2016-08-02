#include <stdio.h>
int main(void){
  int data[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  int dataa[3][3]={{1,2,3},{4,5,6},{7,8,9}};
  int i,j,r,c;
  printf("%d\n",data[1][-1]);
  printf("%d\n",dataa[1][-1]);
  /* for (i=0;i<3;i++){
    for(j=0;j<3;j++){
      printf(" %d  ",dataa[i][j]);
    }
    printf("\n");
  }
  while (1){
    scanf("%d %d",&r,&c);
    printf(">>%d\n",dataa[r][c]);
  }
  return 0;*/
}
