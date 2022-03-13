#include <stdio.h>				//기본 입출력 헤더
#pragma warning(disalbe 4996)	//ex-oj 에러 방지용

int *MAX(int ar[]);	//가장 큰 원소의 주소 반환
int *MIN(int ar[]);	//가장 작은 원소의 주소 반환

int main(void) {
	
	int N;			//테스트 케이스 개수
	int ar[100];	//원소 저장용 배열
	int n=0;		//N 반복용 변수
	int flag;		//출력 여부 확인용
	int *p;			//ar[] 탐색용 포인터
	int *M=NULL;	//최댓값 주소 저장용 포인터
	int *m=NULL;	//최솟값 주소 저장용 포인터
	int *s=NULL;	//출력 시작 주소 저장용 포인터
	int *e=NULL;	//출력 끝 주소 저장용 포인터
	scanf("%d",&N);	//N 입력
	
	//N번 반복
	for(n=0;n<N;n++){
		//p이용하여 ar[]탐색
		for(p=ar;p<ar+100;p++){
			scanf("%d",p);	//ar[]에 원소 입력 후 저장
			if(*p==0)break;	//입력 종료 조건
		}
		flag = 1;		//flag 초기화
		M = MAX(ar);	//M에 ar[] 최댓값 원소의 주소 저장
		m = MIN(ar);	//m에 ar[] 최솟값 원소의 주소 저장
		if(M>m){		//M이 m보다 뒤쪽에 위치한 경우
			s=m;		//s에 m저장
			e=M;		//e에 M저장
		}
		else {			//m이 M보다 뒤쪽에 위치한 경우
			s=M;		//s에 M저장
			e=m;		//e에 m저장
		}
		//시작 위치(최댓값 주소 + 1)부터 끝 위치(최솟값 주소 - 1)까지 반복
		for(p=s+1;p<e;p++){
			printf("%d ",*p);	//원소 출력
			if(flag==1)flag=0;	//원소 출력 여부 flag에 저장
		}
		if(flag==1)printf("none");	//원소를 출력하지 않은 경우 none 출력
		printf("\n");	//출력예시용 줄띄움
	}
	
	return 0;
}

//가장 큰 원소의 주소 반환
int *MAX(int ar[]){
	int *p;			//ar[] 탐색용
	int M = *ar;	//최댓값 저장용
	int *idx = ar;	//최댓값 주소 저장용
	//p를 이용해 ar[] 탐색
	for(p=ar;p<ar+100;p++){
		if(*p==0)break;	//범위를 벗어난 경우 반복문 탈출
		if(*p>M){		//현재 저장된 M보다 더 큰 원소 찾은 경우
			M = *p;		//M에 더 큰 원소 저장
			idx = p;	//해당 원소의 주소 저장
		}
	}
	return idx;	//가장 큰 원소의 주소 리턴
}

//가장 작은 원소의 주소 반환
int *MIN(int ar[]){
	int *p;			//ar[] 탐색용
	int m = *ar;	//최솟값 저장용
	int *idx = ar;	//최솟값 주소 저장용
	for(p=ar;p<ar+100;p++){
		if(*p==0)break;	//범위를 벗어난 경우 반복문 탈출
		if(*p<m){		//현재 저장된 m보다 더 작은 원소 찾은 경우
			m = *p;		//m에 더 작은 원소 저장
			idx = p;	//해당 원소의 주소 저장
		}
	}
	return idx;	//가장 작은 원소의 주소 리턴
}