#include <stdio.h>
#include <stdlib.h>
typedef struct{
  char* title;
  char* artist;
  int num;
  char** mtitle;
} Album;
void init(Album* a, char* title, char* artist, int num, char** mtitle){
  int i;
  a->title=title;
  a->artist=artist;
  a->num=num;
  a->mtitle=(char**)malloc(sizeof(char*)*num);
  for (i=0;i<num;i++){
    a->mtitle[i]=mtitle[i];
  }
}
void show(Album album){
  int i;

  printf("%s / %s\n", album.title, album.artist); 
  for(i=0; i<album.num; i++){
    printf("%3d  ", i+1);
    printf("%s\n", album.mtitle[i]);
  }
}
int main(void){
  Album album;
  char *songs[]={"a","b","c"};
  init(&album, "aha", "Yosuke", 3, songs);
  show(album);
}
