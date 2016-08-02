#include <stdio.h>
#include <stdlib.h>
int main(void){
  int i, num;
  FILE *fp;
  fp=fopen("output.txt", "w");
  if (fp==NULL){
    printf("file open error\n");
    exit(1);
  }
  srand((unsigned)time(NULL));
  for (i=0; i<100; i++){
    num=(int)(rand()/(RAND_MAX+1.0)*6)+1;
    fprintf(fp, "%d\n", num);
  }
  close(fp);
  return 0;
}
