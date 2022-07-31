/*********************************************************************
*Title : 평균은 넘겠지
*Number : 4344번
*Author : dkxkqkrtkddn
*Description : 대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.
*Input : 첫째 줄에는 테스트 케이스의 개수 C가 주어진다.둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
*Output : 각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
*Start Time : 2020년 0월 7일 22시 36분 48초
*End Time : 2020년 0월 7일 시 분 초
*comments program : https://chrome.google.com/webstore/detail/boj-blog-post/ehhcjhfkaiohgflkjifmageahncijacd?hl=ko
*********************************************************************/

#include<stdio.h>

int main(void) {

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		double avg = 0;
		int cnt = 0;
		int score[1000];
		for (int j = 0; j < n; j++) {
			scanf("%d", &score[j]);
			avg += score[j];
		}
		avg /= (double)n;
		for (int j = 0; j < n; j++) {
			if ((double)score[j] > avg)cnt++;
		}
		printf("%.3lf%%\n", (double)cnt / (double)n * (double)100);
	}

	return 0;
}