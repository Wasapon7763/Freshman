#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void init();
void disp();
void solve1(int p, int r);
void solve2();
int board[9][9];
int main(void){
  int i,j,k;
  init();
  disp();
  return 0;
}
void disp(){
  int i,j;
  for (i=0;i<9;i++){
    for (j=0;j<9;j++){
      printf("%2d ",board[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}
void init(){
  int i,j;
  char str[9];
  for (i=0;i<9;i++){
    fgets(str, 11, stdin);
    for (j=0;j<9;j++){
      if (str[j]!=' '){
	board[i][j]=(int)str[j]-(int)'0';
      }
      else{
	board[i][j]=0;
      }
    }
  }
}
void solve1(int p, int r){
  int i,j,c=0,n;
  int ava[9]={1,2,3,4,5,6,7,8,9};
  int cubex,cubey;
  cubex=(r/3)*3;
  cubey=(p/3)*3;
  for (i=0;i<9;i++){
    if (board[p][i]!=0&&ava[board[p][i]-1]!=-1){
      ava[board[p][i]-1]=-1;
    }
    if (board[i][r]!=0&&ava[board[i][r]-1]!=-1){
      ava[board[i][r]-1]=-1;
    }
    if (board[cubey+i/3][cubex+i%3]!=0&&ava[board[cubey+i/3][cubex+i%3]-1]!=-1){
      ava[board[cubey+i/3][cubex+i%3]-1]=-1;
    }
  }
  if (p==r){
    for (i=0;i<9;i++){
      if (board[i][i]!=0&&ava[board[i][i]-1]!=-1){
	ava[board[i][i]-1]=-1;
      }
    }
  }
  if (p+r==8){
    for (i=0;i<9;i++){
      if (board[i][8-i]!=0&&ava[board[i][8-i]-1]!=-1){
	ava[board[i][8-i]-1]=-1;
      }
    }
  }
  for (i=0;i<9;i++){
    if (ava[i]==-1) c++;
    else n=i;
  }
  if (c==8) board[p][r]=ava[n];
}
void solve2(){
  int i,j,k,l,c,n1,n2,p,r;
  for (p=0;p<3;p++){
    for (r=0;r<3;r++){
      int ava[9]={1,2,3,4,5,6,7,8,9};
      int abox[3][3]={0};
      int box[3][3];
      for (i=0;i<9;i++){//box 1 1
	if (board[(i/3)+3*p][(i%3)+3*r]!=0&&ava[board[(i/3)+3*p][i%3+3*r]-1]!=-1){
	  ava[board[i/3+3*p][i%3+3*r]-1]=-1;
	  abox[i/3][i%3]=-1;
	}
      }

      /* for (i=0;i<9;i++){
	 printf("%d ",ava[i]);
	 }
	 printf("\n");
      */
      for (i=0;i<9;i++){
	for(j=0;j<3;j++){
	  for (k=0;k<3;k++){
	    box[j][k]=abox[j][k];
	  }
	}
	if (ava[i]==-1){
	  continue;
	}
	for (j=0;j<3;j++){
	  for (k=0;k<9;k++){
	    if (board[j+3*p][k]==ava[i]){
	      for (l=0;l<3;l++){
		if (box[j][l]!=-1) box[j][l]=-1;
	      }
	    }
	    if (board[k][j+3*r]==ava[i]){
	      for (l=0;l<3;l++){
		if (box[l][j]!=-1) box[l][j]=-1;
	      }
	    }
	  }
	}
	if (p==r){
	  for (j=0;j<9;j++){
	    if (board[j][j]==ava[i]){
	      for (k=0;k<3;k++){
		if (box[k][k]!=-1) box[k][k]=-1;
	      }
	    }
	  }
	}
	if (p+r==2){
	  for (j=0;j<9;j++){
	    if (board[j][8-j]==ava[i]){
	      for (k=0;k<3;k++){
		if (box[k][2-k]!=-1) box[k][2-k]=-1;
	      }
	    }
	  }
	}
	/* printf("\n");
	   for (j=0;j<3;j++){
	   for (k=0;k<3;k++){
	   printf("%2d ",box[j][k]);
	   }
	   printf("\n");
	   }*/
	c=0;
	for (j=0;j<3;j++){
	  for (k=0;k<3;k++){
	    if (box[j][k]!=-1){
	      c++;
	      n1=j;
	      n2=k;
	    }
	  }
	}
	if (c==1) board[n1+3*p][n2+3*r]=ava[i];
      }

    }
  }
}
