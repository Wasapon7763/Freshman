#include <stdio.h>
#include <string.h>
int main(void){
  char str[100];
  int i;
  printf("Input?: ");
  fgets(str, 100, stdin);
  FILE *fp;
  fp=fopen("data.txt", "w");
  for (i=0; i<strlen(str)-1; i++){
    fprintf(fp, "%c", str[strlen(str)-2-i]);
  }
  fclose(fp);
  return 0;
}
