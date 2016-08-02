#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  int id;
  char code[31];
  int age;
  int height;
}PEOPLE;
int item_num;
int str_search(char str[], int n, char key[]){
  char last[strlen(key)];
  int i,j,check=0;
  int len=strlen(key);
  if (n==strlen(str)){
    n--;
  }
  for (i=0;i<len;i++){
    last[i]=str[n-len+i+1];
  }
  for (i=len-1;i>=0;i--){
    if(str[n-i]==key[len-i-1]){
      check++;
    }
  }
  if (check==len){
    for (j=0;j<len;j++){
      str[n-len+j+1]=last[j];
    }
    return n-len+1;
  }
  for (i=len-1;i>=0;i--){
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
	return i;
      }
    }
  }
  return -1;
}
int main(int argc, char *argv[]){
  int i,pos;
  PEOPLE *data;
  FILE*fp;
  if (argc!=3) exit(1);
  if ((fp=fopen(argv[1],"r"))==NULL){
    printf("Cannnot open%s/n",argv[1]);
    exit(1);
  }
  fscanf(fp, "%d", &item_num);
  if ((data=(PEOPLE *)malloc(sizeof(PEOPLE)*item_num))==NULL){
    printf("memory error");
    exit(1);
  }
  for (i=0;i<item_num;i++){
    fscanf(fp,"%d\n",&data[i].id);
    fgets(data[i].code, 31, fp);
    fscanf(fp,"%d\n", &data[i].age);
    fscanf(fp,"%d\n",&data[i].height);
  }
  for (i=0;i<item_num;i++){
    if ((pos=str_search(data[i].code,strlen(data[i].code),argv[2]))!=-1){
	printf("id:  %d\ncode: %s\npos=%d\n\n\n",data[i].id,data[i].code,pos);
      }
  }
  return 0;
}
