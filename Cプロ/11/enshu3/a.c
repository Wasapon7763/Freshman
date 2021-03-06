#include <stdio.h>
#include <stdlib.h>
#include "newsort.h"
int main(void){
  PEOPLE *data;
  int i, item_num;
  FILE *fp;
  if ((fp=fopen("data.txt","r"))==NULL){
    printf("Cannot open the file\n");
    exit(1);
  }
  fscanf(fp,"%d",&item_num);
  if ((data=(PEOPLE *)malloc(sizeof(PEOPLE)*item_num))==NULL){
    printf("Memory error\n");
    exit(1);
  }
  item_num=25;
  for (i=0;i<item_num;i++){
    fscanf(fp,"%d\n",&data[i].id);
    fgets(data[i].code, 31, fp);
    fscanf(fp,"%d\n", &data[i].age);
    fscanf(fp,"%d\n",&data[i].height);
  }
  selectsort(data,item_num);
  for (i=0;i<item_num;i++)
    printf("id=%d, height=%d\n",data[i].id, data[i].height);
  printf("\n");
  quick_sort(data, 0, item_num-1);
  for (i=0;i<item_num;i++)
    printf("id=%d, code=%s\n",data[i].id, data[i].code);
  return 0;
}
