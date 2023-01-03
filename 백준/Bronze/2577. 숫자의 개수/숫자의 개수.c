#include<stdio.h>

int main() {

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int result = a * b * c;
	int n[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		int num = result;
		int cnt = 0;
		while (num != 0) {
			if (num % 10 == i)cnt++;
			num /= 10;
		}
		n[i] = cnt;
		printf("%d\n", n[i]);
	}
	return 0;
}