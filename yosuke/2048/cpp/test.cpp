#include <iostream>
#include <windows.h>
using namespace std;
int main(){
  while(true){
    if(GetAsyncKeyState(VK_UP)){
      cout<<"hi"<<endl;
    }
  }
}
