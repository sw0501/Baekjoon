#include<stdio.h>

int main(void) {
		int n;
		scanf("%d", &n);

		// 1 3 6 10 15 21 28
		// 1 2 3 4 5 6 7
		// 2 3 4 5 6 7 8 

		int sum = 0;
		int a = 0, b = 1;
		for (int i = 1;; i++) {
			sum += i;
			a++;
			if (sum >= n) {
				sum -= i;
				break;
			}
		}
		if (a % 2 == 0) {
			int c = a;
			a = b;
			b = c;
			for (int i = sum + 1; i < n; i++) {
				b--;
				a++;
			}
		}
		else {
			for (int i = sum + 1; i < n; i++) {
				a--;
				b++;
			}
		}

		printf("%d/%d\n", a, b);


	return 0;
}