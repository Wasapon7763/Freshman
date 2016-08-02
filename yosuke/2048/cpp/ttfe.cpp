#include <iostream>
using namespace std;
void disp(int board[4][4]){
  for (int i=0;i<4;i++){
    cout<<"                    ";
    for (int j=0;j<4;j++){
      cout<<board[i][j]<<"    ";
    }
    cout<<endl<<endl;
  }
}
void left(int *board){
}
void right(int *board){
}
void up(int *board){
}
void down(int *board){
}
int main(){
  char key;
  int board[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
  while (1){
    cin>>key;
    switch (key){
    case 'a':
      left(board);
      break;
    case 'd':
      right(board);
      break;
    case 'w':
      up(board);
      break;
    case 's':
      down(board);
      break;
    }
    disp(board);
  }
}
