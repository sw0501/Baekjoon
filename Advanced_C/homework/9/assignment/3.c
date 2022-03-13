#include <stdio.h>	//기본입출력 헤더
#pragma warning(disalbe 4996)	//OJ 에러방지용 코드

//main function
int main(void) {
	char str[100];		//문자열 저장 배열
	char *c;			//문자열 탐색 포인터
	char *s = str;		//출력할 단어 시작 포인터
	char *e;			//출력할 단어 끝 포인터
	int ans_len = 0;	//최대 길이 저장하는 정수형 변수 선언
	
	//배열 순회하는 반복문
	for(c = str;c<str+100;c++){ 
		scanf("%c",c);	//사용자로 부터 값 입력
		if(*c=='#')break;	//입력 탈출 조건
	}
	
	//배열 순회하는 반복문
	for(c = str;c<str+100;c++){	
		//탐색중인 배열이 소문자인 경우 출력 끝을 나타내는 포인터 e에 해당 위치 저장
		if(*c>='a'&&*c<='z')e = c;	
		//소문자가 아닌 경우
		else {
			//단어 최대 길이 비교 후 저장
			ans_len = (ans_len>(int)(e-s)+1?ans_len:(int)(e-s)+1);
			//단어 시작 포인터 s 부터 단어 끝 포인터 e 까지 반복
			for(;s<=e;s++){
				//단어 출력하면서 시작 포인터 s증가
				printf("%c",*s);
			}
			printf("\n"); //출력 조건 맞추기 위해 줄띄움
			//다음 출력을 시작할 소문자를 찾을때까지 반복
			while(!(*c>='a'&&*c<='z')){
				if(*c=='#'){	//종료 조건일 경우
					printf("%d\n",ans_len);	//최대 단어 길이 출력
					return 0;	// main 함수 종료
				}
				c++;	//배열 위치 증가
			}
			s = c;	//시작 위치 지정
			e = c;	//종료 위치 지정
		}
	}
	
	return 0;
}