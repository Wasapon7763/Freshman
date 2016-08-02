#include <stdio.h>
#include <windows.h>
int main(){
  while(1){
    //仮想キーコードは、WINUSER.H ヘッダファイルで記載されている

    if(GetAsyncKeyState (VK_CONTROL)){
      //CTRLキーが押されている
      printf("CTRL\n");
    }
    if(GetAsyncKeyState (VK_MENU)){
      //ALTが押されている
      printf("ALT\n");
    }
    if(GetAsyncKeyState (VK_SHIFT)){
      //SHIFTが押されている
      printf("SHIFT\n");
    }
    if(GetAsyncKeyState (VK_LBUTTON)){
      //マウス左ボタンが押されている
      printf("Mouse Left\n");
    }
    if(GetAsyncKeyState (VK_RBUTTON)){
      //マウス右ボタンが押されている
      printf("Mouse Right\n");
    }
    if(GetAsyncKeyState ('A')){
      //Aキーが押されている
      printf("A\n");
    }
    if(GetAsyncKeyState ('1')){
      //1が押されている
      printf("1\n");
    }
    Sleep(10);
  }
  return 0;
}
