#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
  printf("\n");
  int num[3][3]={{000},{000},{000}};//board
  int input=3;
  int count=0;
  int i,j;
  int k=1;
  srand((int)time(NULL));
  while (input!=0){
    if (count==0){
      if (starting()==2)
	break;
    }
    if (count==0){
      printf("Description: Enter a number that corresponds to following.\n\n\n");
      for (i=0;i<3;i++){
	printf("        ");
	for (j=0;j<3;j++){
	  printf(" %d   ",k);
	  k++;
	}
	printf("\n\n");
      }
      disp(num);
    }
    printf("\n");
    scanf("%d",&input);
    if (check(input,num)==10){
      printf("\n         Wrong action!\n");
      continue;
    }
    printf("\n%d\n",input);
    change(input,num);
    if (count==0)
      fcomchange(num);
    else if(count<4){
      comchange(num);
    }
    disp(num);
    count=winning(num,count);
    if (count==99){
      break;
    }
    else if(count==4){
      printf("\n            Draw\n\n");
      break; 
    }
      count++;
  }
  return 0;
}
int starting(){
  int i;
  printf("       ~ TIC TAC TOE ~\n\n");
  printf("           1.PLAY\n\n");
  printf("           2.EXIT\n\n");
  scanf("%d",&i);
  return i;
}
//diaplay board complete
int disp(int ii[3][3]){
  int i,j;
  printf("\n\n");
  for (i=0;i<3;i++){
    printf("        ");
    for (j=0;j<3;j++){
      if (ii[i][j]==1)
	printf(" o   ");
      if (ii[i][j]==2)
	printf(" x   ");
      if (ii[i][j]==0)
	printf(" -   ");
    }
    printf("\n\n");
  }
}
int winning(int ii[3][3],int end){  
  int comp[8];
  int user[8];
  int j,k;
  for (j=0;j<3;j++){
    user[j]=0;
    user[j+3]=0;
    comp[j]=0;
    comp[j+3]=0;
    for (k=0;k<3;k++){
      if (ii[j][k]==1)
	user[j]++;
      if (ii[k][j]==1)
	user[j+3]++;
      if (ii[j][k]==2)
	comp[j]++;
      if (ii[k][j]==2)
	comp[j+3]++;
    }
  }
  comp[6]=0;
  comp[7]=0;
  user[6]=0;
  user[7]=0;
  for (j=0;j<3;j++){
    if (ii[j][j]==1)
      user[6]++;
    if (ii[j][2-j]==1)
      user[7]++;
    if (ii[j][j]==2)
      comp[6]++;
    if (ii[j][2-j]==2)
      comp[7]++; 
  }
  for (j=0;j<8;j++){
    if (user[j]==3){
      printf("\n           You win!\n");
      end=99;
      break;
    }
    if (comp[j]==3){
      printf("\n          You lose!\n");
      end=99;
      break;
    }
  }
  return end;
}
int check(int ii,int iii[3][3]){
  int i=ii%3;
  double dd=(double)ii;
  double d=dd/3;
  if (i==0){
    i=3;
  }
  if (d>2){
    if (iii[0][i-1]!=0)
      ii=10;
  }
  if ((d>1)&&(d<=2)){
    if (iii[1][i-1]!=0)
      ii=10;
  }
  if ((d>0)&&(d<=1)){
    if (iii[2][i-1]!=0)
      ii=10;
  }
  return ii;

}
//move by user
int change(int ii,int iii[3][3]){
  int i=ii%3;
  double dd=(double)ii;
  double d=dd/3;
  if (i==0){
    i=3;
  }
  if (d>2){
    iii[0][i-1]=1;
  }
  if ((d>1)&&(d<=2)){
    iii[1][i-1]=1;
  }
  if ((d>0)&&(d<=1)){
    iii[2][i-1]=1;
  }
  return iii[3][3];
}
//first move by computer complete
int fcomchange(int ii[3][3]){
  int r,rr;
  while(1){
    r=rand()%2;
    rr=rand()%2;
    if (r==1)
      r=2;
    if (rr==1)
      rr=2;
    if (ii[r][rr]==0){
      ii[r][rr]=2;
      break;
    }
  }
  return ii[3][3];
}
int comchange(int ii[3][3]){
  int j,k;
  int enable=1;
  int danger[8];
  int win[8];
  //todome sagashi
  for (j=0;j<3;j++){
    win[j]=0;
    win[j+3]=0;
    for (k=0;k<3;k++){
      if (ii[j][k]==2)
	win[j]++;
      if (ii[k][j]==2)
	win[j+3]++;
    }
  }
  win[6]=0;
  win[7]=0;
  for (j=0;j<3;j++){
    if (ii[j][j]==2)
      win[6]++; //riht down across
    if (ii[j][2-j]==2)
      win[7]++; //right up across
  }
  //todome
    for (j=0;j<3;j++){
    if (win[j]==2 && enable==1){ 
      for (k=0;k<3;k++){ 
       	if (ii[j][k]==0){
	  ii[j][k]=2;
	  enable=0;
	  break;
	}
      }
    }
    if (win[j+3]==2 && enable==1){
	for (k=0;k<3;k++){ 
	  if (ii[k][j]==0){
	  ii[k][j]=2;
	  enable=0;
	  break;
	  }
	}
    }
  }
  if (win[6]==2 && enable==1){
    for (j=0;j<3;j++){
      if (ii[j][j]==0){
	ii[j][j]=2;
	enable=0;
	break;
      }
    }
  }
  if (win[7]==2 && enable==1){
    for (j=0;j<3;j++){
      if (ii[j][j]==0){
	ii[j][2-j]=2;
	enable=0;
	break;
      }
    }
  }
  //finding danger0-5
  for (j=0;j<3;j++){
    danger[j]=0;
    danger[j+3]=0;  
    for (k=0;k<3;k++){
      if (ii[j][k]==1)
	danger[j]++;
      if (ii[k][j]==1)
	danger[j+3]++;
    }
  }
  //finding danger 6-7
  danger[6]=0;
  danger[7]=0;
  for (j=0;j<3;j++){
    if (ii[j][j]==1)
      danger[6]++; //riht down across
    if (ii[j][2-j]==1)
      danger[7]++; //right up across
  }
  //avoiding danger0-5
  for (j=0;j<3;j++){
    if (danger[j]==2 && enable==1){ 
      for (k=0;k<3;k++){ 
       	if (ii[j][k]==0){
	  ii[j][k]=2;
	  enable=0;
	  break;
	}
      }
    }
    if (danger[j+3]==2 && enable==1){
	for (k=0;k<3;k++){ 
	  if (ii[k][j]==0){
	  ii[k][j]=2;
	  enable=0;
	  break;
	  }
	}
    }
  }
  //avoiding 6-7
  if (danger[6]==2 && enable==1){
    for (j=0;j<3;j++){
      if (ii[j][j]==0){
	ii[j][j]=2;
	enable=0;
	break;
      }
    }
  }
  if (danger[7]==2 && enable==1){
    for (j=0;j<3;j++){
      if (ii[j][2-j]==0){
	ii[j][2-j]=2;
	enable=0;
	break;
      }
    }
  }
  if (enable==1){
    int r,rr;
    for(j=0;j<50;j++){
      r=rand()%2;
      rr=rand()%2;
      if (r==1)
	r=2;
      if (rr==1)
	rr=2;
      if (ii[r][rr]==0){
	ii[r][rr]=2;
	enable=0;
	break;
      }
    }
  }
  printf("\n%d\n",enable);
  if (enable==1){
    int hi=1;
    for (j=0;j<3;j++){
      for (k=0;k<3;k++){
        if (ii[j][k]==0){
	  ii[j][k]=2;
	  hi=0;
	  break;
	}
      }
      if (hi==0)
	break;
    }
  }
  return ii[3][3];
}
