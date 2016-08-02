#include<stdio.h>

void gcdlcm(int m, int n, int *gcd, int *lcm){

	/* ここから編集 */
  int r;
  int a=m;
  int b=n;
  while (1){
    r=m%n;
    m=n;
    n=r;
    if (r==0){
      *gcd=m;
      break;
    }
  }
  *lcm=a*b/m;

	/* ここまで編集 */

	return;
}

int main(void){
	int m, n, gcd, lcm;

	printf("Input two integers :\n");
	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);

	gcdlcm(m, n, &gcd, &lcm);

	printf("gcd(%d,%d) = %d\n", m, n, gcd);
	printf("lcm(%d,%d) = %d\n", m, n, lcm);

	return 0;
}
