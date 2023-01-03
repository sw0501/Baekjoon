/*********************************************************************
*Title : 한수
*Number : 1065번
*Author : dkxkqkrtkddn
*Description : 어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
*Input : 첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.
*Output : 첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
*Start Time : 2020년 0월 11일 13시 12분 59초
*End Time : 2020년 0월 11일 시 분 초
*comments program : https://chrome.google.com/webstore/detail/boj-blog-post/ehhcjhfkaiohgflkjifmageahncijacd?hl=ko
*********************************************************************/

#include<stdio.h>

int x(int num);

int main(void) {

	int n, cnt=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if(x(i))cnt++;
	}
	printf("%d", cnt);

	return 0;
}

int x(int num) {
	int n, m, l, flag = 1;
	n = num % 10;
	num /= 10;
	m = num % 10;
	num /= 10;
	while (num != 0) {
		l = num % 10;
		num /= 10;
		if (n - m != m - l) flag = 0;
		n = m;
		m = l;
	}
	return flag;
}