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
int main(int argc, char *argv[]){
  int i;
  int max_age, max_age_id;
  int min_height, min_height_id;
  PEOPLE *data;
  FILE *fp;
  if (argc!=2) exit(1);
  if ((fp=fopen(argv[1],"r")) == NULL){
    printf("Cannot open %s\n", argv[1]);
    exit(1);
  }
  fscanf(fp, "%d", &item_num);
  if ((data=(PEOPLE *)malloc(sizeof(PEOPLE)*item_num)) == NULL){
    printf("memory error\n");
    exit(1);
  }
  for (i=0;i<item_num;i++){
    fscanf(fp, "%d\n", &data[i].id);
    fgets(data[i].code, 31, fp);
    fscanf(fp, "%d\n", &data[i].age);
    fscanf(fp, "%d\n", &data[i].height);
  }
  fclose(fp);
  max_age_id=min_height_id=0;
  max_age=data[0].age;
  min_height=data[0].height;
  i=1;
  while (i<item_num){
    if (data[i].age>max_age){
      max_age=data[i].age;
      max_age_id=i;
    }
    if (data[i].height<min_height){
      min_height=data[i].height;
      min_height_id=i;
    }
    i++;
  }
  printf("Maximun age:\n");
  for (i=max_age_id;i<item_num;i++){
    if (data[i].age==max_age){
      printf("ID:%d\nCODE:%s\nAge:%d\nHeight:%d\n\n",data[i].id,data[i].code,data[i].age,data[i].height);
    }
  }
  printf("Minimun height:\n");
  for (i=min_height_id;i<item_num;i++){
    if (data[i].height==min_height){
      printf("ID:%d\nCODE:%s\nAge:%d\nHeight:%d\n\n",data[i].id,data[i].code,data[i].age,data[i].height);
    }
  }
  return 0;
}
