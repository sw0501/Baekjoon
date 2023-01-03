/*********************************************************************
*Title : 단어의 개수
*Number : 1152번
*Author : dkxkqkrtkddn
*Description : 영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.
*Input : 첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어진다. 이 문자열의 길이는 1,000,000을 넘지 않는다. 단어는 띄어쓰기 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다. 또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.
*Output : 첫째 줄에 단어의 개수를 출력한다.
*Start Time : 2020년 0월 11일 17시 31분 54초
*End Time : 2020년 0월 11일 시 분 초
*comments program : https://chrome.google.com/webstore/detail/boj-blog-post/ehhcjhfkaiohgflkjifmageahncijacd?hl=ko
*********************************************************************/

#include<stdio.h>

int main(void) {

	char c;
	int cnt = 0;
	int flag = 0;
	while (1) {
		scanf("%c", &c);
		if (c != ' '&&c != '\n')flag = 1;
		if (flag&&c == ' ') {
			cnt++;
			flag = 0;
		}
		else if (flag&&c == '\n') {
			cnt++;
			flag = 0;
		}
		if (c == '\n')break;
	}
	printf("%d", cnt);
	return 0;
}