#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void init();
void disp();
void solve();
int board[9][9]; //盤面
int count=0; //出力回数
int main(void){
  init();
  disp();
  solve();
  if (count==1) printf("Solution not found\n"); //解の出力が行われ無かった場合、解なし
  return 0;
}
void init(){ //初期設定
  int i,j,n;
  char str[50];
  for (i=0;i<9;i++){ //盤面の入力
    fgets(str, 50, stdin);
    if (str[0]==';') i--;
    j=0;
    while (str[j]!=';'){
      if (str[j]!=' '){
	n=(int)str[j]-(int)'0';
	board[i][j]=n;
      }
      else{
	board[i][j]=0;
      }
      j++;
    }
  }
}
void disp(){ //盤面出力
  int i,j,k;
  count++;
  for (i=0;i<10;i++){
    if (i%3==0){
      for (j=0;j<4;j++){
	printf("+");
	for (k=0;k<7&&j!=3;k++){
	  printf("-");
	}
      }
      printf("\n");
    }
    for (j=0;j<9&&i<9;j++){
      if (j%3==0) printf("| ");
      printf("%-2d",board[i][j]);
    }
    if (i<9) printf("| \n");
  }
  printf("\n");
}
int checkava(int n, int x, int y){
  int i,j;
  for (i=0;i<9;i++) //横
    if (board[x][i]==n) return 0;
  for (i=0;i<9;i++) //縦
    if (board[i][y]==n) return 0;
  for (i=0;i<3;i++) //ボックス
    for (j=0;j<3;j++)
      if (board[3*(x/3)+i][3*(y/3)+j]==n) return 0;
  if (x==y){ //対角線上にある場合(右上がり)
    for (i=0;i<9;i++)
      if (board[i][i]==n) return 0;
  }
  if (x+y==8){ //対角線上にある場合(右下がり)
    for (i=0;i<9;i++)
      if (board[i][8-i]==n) return 0;
  }
  return 1;
}
void solve(){
  int i,j,x=-1,y=-1,ava=1;
  for (i=0;i<9;i++){ //開いているマスを探す
    for (j=0;j<9;j++){
      if (board[i][j]==0){
	x=i;
	y=j;
	break;
      }
    }
  }
  if (x==-1&&y==-1){ //開いているマスがない場合、盤面出力
    printf("Solution found!\n");
    disp();
    return;
  }
  for(ava=1;ava<10;ava++){
    if (checkava(ava, x, y)==1){ //avaが指定されたマスに入りうる数字であるかどうか
      board[x][y]=ava; //そのマスをavaに
      solve(board); //solve関数呼び出し
      board[x][y]=0; //うまくいかなかったらリセット
    }
  }
}
