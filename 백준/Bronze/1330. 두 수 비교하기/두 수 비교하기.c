/*********************************************************************
*Title : 두 수 비교하기
*Number : 1330번
*Author : dkxkqkrtkddn
*Description : 두 정수 A와 B가 주어졌을 때, A와 B를 비교하는 프로그램을 작성하시오. 
*Input : 첫째 줄에 A와 B가 주어진다. A와 B는 공백 한 칸으로 구분되어져 있다. 
*Output : 첫째 줄에 다음 세 가지 중 하나를 출력한다.A가 B보다 큰 경우에는 '>'를 출력한다.A가 B보다 작은 경우에는 '<'를 출력한다.A와 B가 같은 경우에는 '=='를 출력한다. 
*Start Time : 2020년 0월 1일 18시 45분 22초
*End Time : 2020년 0월 1일 시 분 초
*comments program : https://chrome.google.com/webstore/detail/boj-blog-post/ehhcjhfkaiohgflkjifmageahncijacd?hl=ko
*********************************************************************/

#include<stdio.h>

int main(void) {
    int a,b;
    scanf("%d %d",&a,&b);
    if(a==b)printf("==");
    else if(a>b)printf(">");
    else printf("<");
	return 0;
}