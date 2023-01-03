/*********************************************************************
*Title : 별 찍기 - 1
*Number : 2438번
*Author : dkxkqkrtkddn
*Description : 첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제
*Input : 첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
*Output : 첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.
*Start Time : 2019년 2월 25일 19시 39분 12초
*End Time : 2019년 2월 25일 시 분 초
*********************************************************************/
#include<stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	char a = '*';
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			printf("%c", a);
		}
		printf("\n");
	}


	return 0;
}