#include <stdio.h>
#include <string.h>
int str_search(char str[], int n, char key[]){
  char last[strlen(key)];
  int i,j,check=0;
  int len=strlen(key); //pqr 3
  if (n==strlen(str)){
    n--;
  }
  for (i=0;i<len;i++){//banpei
    last[i]=str[n-len+i+1];
  }
  for (i=len-1;i>=0;i--){//checking last==banpei
    if(str[n-i]==key[len-i-1]){
      check++;
    }
  }
  if (check==len){//if last==banpei return last
    for (j=0;j<len;j++){
      str[n-len+j+1]=last[j];
    }
    return n-len+2;
  }
  for (i=len-1;i>=0;i--){//banpei dainyu
    str[n-i]=key[len-i-1];
  }
  for (i=0;i<=n;i++){
    if (str[i]==key[0]&&i!=n-len+1){
      for (j=1;j<len;j++){
	if (str[i+j]!=key[j]){
	  break;
	}
      }
      if (j==len){
	for (j=0;j<len;j++){
	  str[n-len+j+1]=last[j];
	}
	return i+1;
      }
    } 
  }
  return -1;
}
int main(void){
  int n=26;
  char s[26]="abcdefghijklmnopqrstuvwxyz";
  char key[4]={'p','q','r','\0'};
  printf("%s starts at %d\n",key,str_search(s,n,key));
  return 0;
}
