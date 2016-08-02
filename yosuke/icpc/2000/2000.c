#include <stdio.h>
int main(void){
  int i,j,locx,locy;
  int count=0;
  int x=10,y=10;
  int n,m,l;
  int result[500];
  while (1){
    int map[20][20];
    for (i=0;i<20;i++){
      for (j=0;j<20;j++){
	map[i][j]=0;
      }
    }
    scanf("%d",&n);
    if (n==0){
      end(result,count);
      break;
    }
    for (i=0;i<n;i++){
      scanf("%d %d",&locx,&locy);
      locy=20-locy;
      map[locy][locx]=1;
    }
    scanf("%d",&m);
    char d[m];
    int l[m];
    for (i=0;i<m;i++){
      scanf("%s %d",&d[i],&l[i]);
    }
    for (i=0;i<m;i++){
      int movex=0;
      int movey=0;
      if (d[i]=='N'){
	movex=0;
	movey=-1;
      }
      if (d[i]=='S'){
	movex=0;
	movey=1;
      }
      if (d[i]=='W'){
	movex=-1;
	movey=0;
      }
      if (d[i]=='E'){
	movex=1;
	movey=0;
      }
      for (j=0;j<l[i];j++){
	x=x+movex;
	y=y+movey;
	if (map[y][x]==1)
	  map[y][x]=0;
      }
    }
    check(map,result,count);
    count++;
  }
  return 0;
}
int check(int m[20][20],int r[100],int c){
  int i,j;
  int n=0;
  for (i=0;i<20;i++){
    for (j=0;j<20;j++){
      if (m[i][j]==1){
	r[c]=0;
	n=1;
	break;
      }
    }
    if (n==1)
      break;
    if (i==19)
      r[c]=1;
  }
}
int end(int r[100],int c){
  int i;
  for (i=0;i<=c;i++){
    if (r[i]==0)
      printf("No\n");
    if (r[i]==1)
      printf("Yes\n");
  }
}
