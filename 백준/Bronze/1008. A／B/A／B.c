/*********************************************************************
*Title : A/B
*Number : 1008번
*Author : dkxkqkrtkddn
*Description : 두 정수 A와 B를 입력받은 다음, A/B를 출력하는 프로그램을 작성하시오.
*Input : 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)
*Output : 첫째 줄에 A/B를 출력한다. 절대/상대 오차는 10^-9 까지 허용한다.
*Start Time : 2019년 2월 25일 17시 2분 1초
*End Time : 2019년 2월 25일 시 분 초
*********************************************************************/

#include <stdio.h>
int main() {

	int A, B;
	while (1) {
		scanf("%d %d", &A,&B);
		if ((A > 0 && A < 10)&& (B > 0 && B < 10))break;
	}
	printf("%0.9lf", (double)A / B);

	return 0;
}