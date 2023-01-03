
/*********************************************************************
*Title : 별 찍기 - 3
*Number : 2440번
*Author : dkxkqkrtkddn
*Description : 첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제
*Input : 첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
*Output : 첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.
*Start Time : 2019년 2월 25일 20시 12분 8초
*End Time : 2019년 2월 25일 시 분 초
*********************************************************************/
#include<stdio.h>
int main() {

	int N;
	scanf("%d", &N);
	char a = '*';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j<i; j++) {
			printf(" ");
		}
		for (int j = N-i; j >0; j--) {
			printf("%c", a);
		}
		printf("\n");
	}



	return 0;

}