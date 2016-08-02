#include <stdio.h>
#include <stdlib.h>
int main(void){
  int i, hoge;
  int num[6]={0};
  FILE *fp;
  fp=fopen("output.txt","r");
  if (fp==NULL){
    printf("error reading file");
    exit(1);
  }
  for (i=0; i<100; i++){
    fscanf(fp, "%d", &hoge);
    num[hoge-1]++;
  }
  for (i=0; i<6; i++){
    printf("The number of %d: %d\n", i+1, num[i] );
  }
  fclose(fp);
  return 0;
}
