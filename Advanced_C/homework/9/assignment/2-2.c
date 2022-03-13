#include <stdio.h>	//기본입출력 헤더
#pragma warning(disalbe 4996)	//OJ 에러방지용 코드

int passengerN(int n);		//승객 수 확인용 함수
void rebooking(int *ar);	//중복예약 확인용 함수
int changerseat(int *ar);	//중복예약된 고객이 새로 옮길 자리를 리턴하는 함수

int main(void) {
	
	int N;				//승객 수
	int ar[21]={0,};	//승객 별 좌석 예약 
	int *p;				//ar배열 탐색용 포인터
	int CK_pass;		//버스 운행 여부 저장
	
	scanf("%d",&N);		//사용자로부터 승객 수 입력
	
	//승객수만큼 반복
	for(p=ar;p<ar+N;p++){
		scanf("%d",p);	//승객별 예약 좌석 입력
	}
	
	CK_pass = passengerN(N);	//passengerN함수를 통해 운행여부 확인
	printf("%d\n",CK_pass);		//운행여부 출력
	if(CK_pass==-1)return 0;	//운행이 불가능하다면 main 함수 종료
	
	rebooking(ar);				//운행이 가능하다면 중복 좌석 재예약
	
	//중복예약이 해결 된 후에 승객별 예약 좌석 출력
	for(p=ar;p<ar+N;p++){
		printf("%d ",*p);
	}
	printf("\n");	//출력예시용 줄 띄움
	
	return 0;
}

//승객 수 확인용 함수
int passengerN(int n){
	if(n<5)return -1;	//5명 보다 적다면 -1 리턴
	return 0;			//5명 이상인 경우 0 리턴
}

//중복예약 확인용 함수
void rebooking(int *ar){
	int *p;		//ar탐색용 포인터
	int *ps;	//중복예약 확인용 포인터
	int temp;	//예약 좌석 임시저장용 변수
	for(p=ar;p<ar+21;p++){
		if(*p==0)break;	//범위를 벗어났다면 함수 종료
		temp = *p;		//temp에 승객 좌석 임시저장
		//다음 좌석부터 마지막 좌석까지 중복인 좌석이 있는지 확인
		for(ps = p+1;ps<ar+21;ps++){
			//중복 좌석이 있는 경우
			if(*ps==temp){
				//changerseat 함수의 반환 값으로 나온 가장 빠른 비어있는 좌석으로 재배치
				*ps = changerseat(ar);
			}
		}
	}
}

//중복예약된 고객이 새로 옮길 자리를 리턴하는 함수
int changerseat(int *ar){
	int seat[22] = {0,};	//비어있는 좌석 체크 배열
	int *s = seat;			//seat 배열 탐색용 포인터
	int *p;					//ar 배열 탐색용 포인터
	for(p=ar;p<ar+21;p++){	//ar배열 탐색
		if(*p==0)break;		//범위를 벗어난 경우 반복문 탈출
		*(s+*p) += 1;		//예약한 좌석에 해당하는 seat[] 원소 증가
	}
	for(s=seat+1;s<seat+22;s++){		//seat 배열 탐색
		if(*s==0)return (int)(s-seat);	//예약하지 않은 가장 빠른 번호의 좌석번호를 리턴
	}
	return 0;	//경고메세지 방지용 리턴 실제 사용 X
}