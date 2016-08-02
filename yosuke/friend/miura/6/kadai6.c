#include <stdio.h>
int main(void){
  int by,bm,bd,y,m,d,b=0,bb=0;
  int total,leep=0;
  int month[12]={31,59,90,120,151,181,212,243,273,304,334,365};
  printf("生年月日を入力して下さい(yyyy/mm/dd) : ");
  scanf("%d/%d/%d/\n",&by,&bm,&bd);
  printf("今日の日付を入力して下さい(yyyy/mm/dd) : ");
  scanf("%d/%d/%d/\n",&y,&m,&d);
  //2月29日補正
  if (m==2&&d==29){
    d=28;
    b=1;
  }
  //2月29日補正
  if (bm==2&&bd==29){
    bd=28;
    bb=1;
  }
  //閏年考慮なし
  total=365*(y-(by+1))+365-(month[bm-2]+bd)+month[m-2]+d;
  int i;
  //閏年探し（生まれた年と今年を含めない）
  for (i=by+1;i<y;i++){
    if ((i%4==0&&i%100!=0)||i%400==0)
      leep++;
  }
  //今年が閏年の場合
  if ((y%4==0&&y%100!=0)||y%400==0){
    if (m>2||b==1){
      leep++;
    }
  }
  if (bb==1)
    bd=29;
  //生まれた年が閏年の場合
  if ((by%4==0&&by%100!=0)||by%400==0){
    if (bm<=2&&bd<=28)
      leep++;
  }
  total=total+leep;
  printf("今日は生まれてから %d 日目です。\n",total);
  int ny,nm,nd,bool=0;
  int n=10000;
  if (bm==2&&bd==29){
    bd==28;
    bool=1;
  }
  n=n-(365-(month[bm-2]+bd));
  if(bool==1){
    bd=29;
  }
  if ((by%4==0&&by%100!=0)||by%400==0){
    if (bm<=2&&bd<=28){
      n--;
    }
  }
  ny=by+1+n/365;
  n=n-(n/365)*365;
  for (i=0;i<12;i++){
    if ((n-month[i])<=0){
      nm=i+1;
      nd=n-month[i-1];
      break;
    }
  }
  int lleep=0;
  for (i=by+1;i<ny;i++){
    if ((i%4==0&&i%100!=0)||i%400==0){
      lleep++;
    }
  }
  if ((ny%4==0&&ny%100!=0)||ny%400==0){
    if (nm>2){
      lleep++;
    }
  }
  nd=nd-lleep;
  if (nd<=0){
    nd=month[nm]+nd-month[nm-1];
    nm--;
  }
  printf("10000日目は %d年 %d月 %d日です。\n",ny,nm,nd);
  return 0;
}
