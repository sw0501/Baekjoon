#include<stdio.h>

int main(void) {
		
	double a, b, v;
	scanf("%lf %lf %lf", &a, &b, &v);
	double n = (v-a) / (a - b)+1;
	if(n-(int)n>0&&n-(int)n<1)n++;
	printf("%d", (int)n);

	return 0;
}