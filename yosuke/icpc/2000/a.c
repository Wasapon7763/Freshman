#include <stdio.h>
int main(void){
  while (1){
    int map[21][21]={0};
    int m,n;
    int jx,jy;
    int x=10;
    int y=10;
    int i,j;
    scanf("%d",&n);//number of jewels
    if (n==0)
      break;
    for (i=0;i<n;i++){
      scanf("%d %d",&jx,&jy);
      map[20-jy][jx]=1;
    }
    map[10][10]=0;
    scanf("%d",&m);//number of commands
    char dir[m];
    int leng[m];
    for (i=0;i<m;i++){
      scanf("%s %d",&dir[i],&leng[i]);
    }
    for (i=0;i<m;i++){
      switch(dir[i]){
      case 'N':
	for (j=1;j<=leng[i];j++){
	  y=y-1;
	  map[y][x]=0;
	}
	break;
      case 'S':
	for (j=1;j<=leng[i];j++){
	  y=y+1;
	  map[y][x]=0;
	}
	break;
      case 'W':
	for (j=1;j<=leng[i];j++){
	  x=x-1;
	  map[y][x]=0;
	}
	break;
      case 'E':
	for (j=1;j<=leng[i];j++){
	  x=x+1;
	  map[y][x]=0;
	}
	break;
      }
    }
    int c=0;
    for (i=0;i<20;i++){
      for (j=0;j<20;j++){
	if (map[i][j]==1){
	  printf("No\n");
	  i=-1;
	  break;
	}
      }
      if (i==-1){
	break;
      }
      if (i==19)
	c=1;
    }
    if (c==1)
      printf("Yes\n");
  }
  return 0;
}
