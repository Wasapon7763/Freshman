#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
  int world[5][5]={{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
  int status[5]={1,2,10,5,1};//0 lv 1 atk 2 hp 3 sp 4 spd(max10)
  int encount;
  int frame=0;
  srand((unsigned)time(NULL));
  while (1){
    encount=(int)(rand()/(RAND_MAX+1.0)*6);
    printf("%d",encount);
    if (encount==3 && frame!=0){
      battle(status);
      break;
    }
    disp(world);
    move(world);
    frame++;
  }
  return 0;
}
int disp(int w[5][5]){
  int i,j;
  printf("\n\n\n\n\n\n\n\n");
  for (i=0;i<5;i++){
    printf("                         ");
    for(j=0;j<5;j++){
      if (w[i][j]==1)
	printf ("    ⊥",w[i][j]);
      /*if (w[i][j]==2)
	printf ("    ☰",w[i][j]);*/
      if (w[i][j]==0)
	printf ("    ∴");
    }
    printf ("\n\n");
  }
  printf("\n\n\n\n\n\n\n\n");
}
int move(int w[5][5]){
  char command;
  int i,j,x,y;
  for (i=0;i<5;i++){
    for (j=0;j<5;j++){
      if (w[i][j]==1){
	x=i;
	y=j;
	break;
      }
    }
  }
  printf(">> ");
  scanf("%s",&command);
  if (command=='w' && x!=0){
    w[x-1][y]=1;
    w[x][y]=0;
  }
  if (command=='s' && x!=4){
    w[x+1][y]=1;
    w[x][y]=0;
  }
  if (command=='a' && y!=0){
    w[x][y-1]=1;
    w[x][y]=0;
  }
  if (command=='d' && y!=4){
    w[x][y+1]=1;
    w[x][y]=0;
  }
  return w[5][5];
}
int battle(int s[5]){
  int boolean=1;
  int turn=0;
  int command;
  while (boolean==1){
    dispbattle(turn,s);
    printf("            HP: %d\n\n\n",s[2]);
    printf(">> ");
    scanf("%d",&command);
    //t++;
  }
}
int dispbattle(int t,int ss[5]){
  printf("\n\n\n\n\n\n\n\n");
  printf("                                       ⃤");
  if (t==0)
    printf("\n\n\n\n\n\n             　　 敵が現れた！\n");
  else
    printf("\n\n\n\n\n\n                 どうする？\n");
  printf("                                                 1.攻撃\n");
  printf("                                                 2.魔法\n");
  printf("                                                 3.逃げる\n");
  printf("\n\n\n\n\n\n");
}
