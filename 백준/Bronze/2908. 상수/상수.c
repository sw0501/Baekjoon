#include<stdio.h>

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	int n1=0, m1=0;
	for (int i = 0; i < 3; i++) {
		n1 *= 10;
		n1 += n % 10;
		n /= 10;
		m1 *= 10;
		m1 += m % 10;
		m /= 10;
	}
	printf("%d", (n1 > m1 ? n1 : m1));
	return 0;
}