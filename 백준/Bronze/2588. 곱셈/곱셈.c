#include<stdio.h>

int main() {

	int n1,n2;
	int a=0, b=0, c=0, d=0;
	scanf("%d %d",&n1,&n2);
	a = n1 * (n2 % 10);
	b = n1 * ((n2 / 10) % 10);
	c = n1 * ((n2 / 100) % 10);
	d = a + 10 * b + 100 * c;
    printf("%d\n%d\n%d\n%d\n",a,b,c,d);

	return 0;
}