#include <iostream>
using namespace std;
void prime(int i,int *c){
  int j;
  for (j=2;j<(int)i/2;j++){
    if (i%j==0)
      break;
  }
  if (i==1||i==2||j==(int)i/2){
    *c=*c+1;
  }
}
int main() {
  int n=1;
  while (n<201){
    int count=0;
    for (int i=n+1;i<=2*n;i++){
      if (i%2!=0)
        prime(i,&count);
    }
    cout<<n<<" "<<count<<endl;
    n++;
  }
}

