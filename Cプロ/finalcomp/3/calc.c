#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void split(char str[], char *str1, char *str2,int n){ //strを分ける
  int i;
  strcpy(str1,str);
  str1[n]='\0';
  for(i=n+1;str[i]!='\0';i++) str2[i-n-1]=str[i];
  str2[i-n-1]='\0';
}
int poww(int a, int b){ //累乗
  int i,n=1;
  for(i=0;i<b;i++){
    n*=a;
  }
  return n;
}
int fact(int a){ //階乗
  int n=1;
  while (a>0){
    n*=a;
    a--;
  }
  return n;
}
int check(char str[], int n){ //括弧内か外か
  int i,s=-1,e=-1;
  i=0;
  while (str[i]!='\0'){ //（の位置をs、）の位置をe
    if (str[i]=='('){
      s=i;
    }
    if (str[i]==')'){
      e=i;
    }
    i++;
  }
  if (s<n&&n<e&&s!=-1&&e!=-1){
    return 1;
  }
  return 0;
}
int solve(char str[]){
  int i,j,n=0,num;
  char str1[128], str2[128];
  i=0;
  while(str[i]!='\0'){ //strの長さn
    n++;
    i++;
  }
  while(i>=0){ //足し引き
    if((str[i]=='+'||str[i]=='-')&&check(str,i)!=1){
      split(str, str1, str2, i);
      if (i==0){ //数値が負だった場合
	num=str[1]-'0';
	return -1*num;
      }
      if (str[i]=='+')
	return solve(str1)+solve(str2);
      if (str[i]=='-')
	return solve(str1)-solve(str2);
    }
    i--;
  }
  i=n;
  while(i>=0){ //掛け割り
    if((str[i]=='*'||str[i]=='/')&&check(str,i)!=1){
      split(str, str1, str2, i);
      if (str[i]=='*')
	return solve(str1)*solve(str2);
      if (str[i]=='/')
	return solve(str1)/solve(str2);
    }
    i--;
  }
  i=0;
  while(str[i]!='\0'){ //累乗
    if(str[i]=='^'&&check(str,i)!=1){
      split(str, str1, str2, i);
      return poww(solve(str1),solve(str2));
    }
    i++;
  }
  while(i>=0){ //階乗
    if(str[i]=='!'&&check(str,i)!=1){
      split(str, str1, str2, i);
      return fact(solve(str1));
    }
    i--;
  }
  i=0;
  while(str[i]!='\0'){ //括弧
    if(str[i]=='('){
      i++;
      j=0;
      while (str[i]!=')'){
	str1[j]=str[i];
	j++;
	i++;
      }
      return solve(str1);
    }
    i++;
  }
  num=0;
  for(i=0;i<n;i++){ //strを整数に変換
    j=str[i]-'0';
    num+=(j*poww(10,n-i-1));
  }
  return num;
}
int main(void){
  int i=0;
  char str[256],c='0',d;
  fgets(str, 256, stdin);
  while (str[i]!='\n') i++;
  str[i]='\0'; //文字列最後
  printf("%s=",str);
  if (str[0]=='-'){ //先頭の数が負の時、strの最初に0を加える
    i=0;
    while (str[i]!='\0'){
      d=str[i];
      str[i]=c;
      c=d;
      i++;
    }
    str[i]=c;
    str[i+1]='\0';
  }
  printf("%d\n",solve(str));
  return 0;
}
