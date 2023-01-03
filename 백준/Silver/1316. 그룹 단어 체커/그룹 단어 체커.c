/*********************************************************************
*Title : 그룹 단어 체커
*Number : 1316번
*Author : dkxkqkrtkddn
*Description : 그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.
*Input : 첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.
*Output : 첫째 줄에 그룹 단어의 개수를 출력한다.
*Start Time : 2020년 0월 12일 16시 1분 41초
*End Time : 2020년 0월 12일 시 분 초
*comments program : https://chrome.google.com/webstore/detail/boj-blog-post/ehhcjhfkaiohgflkjifmageahncijacd?hl=ko
*********************************************************************/

#include<stdio.h>

int main(void) {

	int n;
	scanf("%d", &n);
	char c[101];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", &c);
		int flag = 1;
		for (int j = 0; c[j]!='\0'; j++) {
			char ch = c[j];
			while (ch==c[j+1]) {
				j++;
			}
			for (int k = j+1; c[k] != '\0'; k++) {
				if (ch == c[k]) {
					flag = 0;
					break;
				}
			}
			if (!flag)break;
		}
		if (flag)cnt++;
	}
	printf("%d", cnt);
	return 0;
}