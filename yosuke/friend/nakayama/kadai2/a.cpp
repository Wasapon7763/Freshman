#include <stdio.h>
int main(void){
  int n=0,i,j;
  int score[10][3]={{92,87,66},{67,89,72},{78,94,79},{59,62,71},{75,72,63},{94,99,97},{83,86,92},{77,81,74},{72,43,55},{96,100,92}};
  int totscore[3];//3科目それぞれの合計点(英語数学理科)
  double ave[10],tot[10];
  for (i=0;i<10;i++){
    tot[i]=score[i][0]+score[i][1]+score[i][2];
    ave[i]=(double)tot[i]/3;
  }
  printf("　英語　数学　理科　平均点\n");
  printf("---------------------------\n");
  for (i=0;i<10;i++){
    printf("%5d %5d %5d  %6.1f\n",score[i][0],score[i][1],score[i][2],ave[i]);
  }
  printf("---------------------------\n");
  for (i=0;i<3;i++){
    totscore[i]=0;
    for (j=0;j<10;j++){
      totscore[i]+=score[j][i];
    }
  }
  printf("英語の平均点:%.1f\n",totscore[0]/10.0);
  printf("数学の平均点:%.1f\n",totscore[1]/10.0);
  printf("理科の平均点:%.1f\n",totscore[2]/10.0);
  for (i=0;i<10;i++){
    n+=tot[i];
  }
  printf("合計点の合計点:%.1f\n",n/10.0);
  n=0;
  for (i=0;i<10;i++){
    n+=ave[i];
  }
  printf("3科目平均点の平均点:%.1f\n",n/10.0);
  return 0;
}
