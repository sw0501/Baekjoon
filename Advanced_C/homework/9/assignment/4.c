#include <stdio.h>	//기본입출력 헤더
#pragma warning(disalbe 4996)	//OJ에러방지용 코드


//main function
int main(void) {
	
	int a[10];			//배열 a
	int b[10];			//배열 n
	int n=0,m=0;		//배열 크기 저장 변수
	int *pa=a,*pb=b;	//배열 탐색용 포인터
	int *i=0;			//반복문용 변수
	int Ma=0;			//최대,최소값 저장 변수
	int *idxa,*idxb;	//배열의 변수의 위치 저장 포인터
	int flag = 0;		//배열 a,b 체크용
	int temp = 0;		//swap 용 임시변수
	int num = 0;		//배열 입력용 변수
	
	//탈출조건까지 반복
	while(1){
		scanf("%d",&num);	//사용자로부터 입력
		if(num==0)break;	//탈출조건일 경우 break;
		*pa = num;			//탈출조건이 아니라면 배열에 저장
		pa++;				//다음 배열 위치에 입력받기 위해 pa++
		n++;				//배열 크기 증가
	}
	//탈출조건까지 반복
	while(1){
		scanf("%d",&num);	//사용자로부터 입력
		if(num==0)break;	//탈출조건일 경우 break;
		*pb = num;			//탈출조건이 아니라면 배열에 저장
		pb++;				//다음 배열 위치에 입력받기 위해 pa++
		m++;				//배열 크기 증가
	}
	
	//m개의 큰 원소들을 찾기 위해 반복
	for(i=a;i<a+n;i++){
		flag = 0;
		pa = i;		//포인터를 정렬되지 않은 배열 시작 부분으로 초기화
		pb = b;		//포인터를 배열 시작 부분으로 초기화
		Ma = *pa;	//가장 큰 변수를 저장할 Ma에 *pa 저장
		idxa = pa;	//포인터 초기화
		idxb = pb;	//포인터 초기화
		
		for(;pa<a+n;pa++){	//a 배열 탐색
			if(*pa>Ma){		//기존 Ma보다 더 큰 수를 찾았다면
				Ma = *pa;	//더 큰 수 저장
				idxa = pa;	//해당 수의 위치 저장
			}
		}
		
		for(;pb<b+m;pb++){	//b 배열 탐색
			if(*pb>Ma){		//기존 Ma보다 더 큰 수를 찾았다면
				Ma = *pb;	//더 큰 수 저장
				idxb = pb;	//해당 수의 위치 저장
				flag = 1;	//배열 체크용
			}
		}
		
		if(flag){			//b배열에서 더 큰 수를 발견했다면
			temp = *i;		//temp에 *i 임시 저장
			*i = *idxb;		//b배열의 가장 큰 값을 *i에 저장
			*idxb = temp;	//*idxb에 임시 저장한 *i값 저장
		}
		else{				//a배열에서 더 큰 수를 발견했다면
			temp = *i;		//temp에 *i 임시 저장
			*i = *idxa;		//a배열의 가장 큰 값을 *i에 저장
			*idxa = temp;	//*idxa에 임시 저장한 *i값 저장
		}
		printf("%d ",*(i));	//정렬된 큰 값 출력
	}
	printf("\n");	//출력 예시용 줄띄움
	
	//m개의 작은 원소들을 찾기 위해 반복
	for(i=b;i<b+m;i++){
		flag = 0;
		pa = a;		//포인터를 정렬되지 않은 배열 시작 부분으로 초기화
		pb = i;		//포인터를 배열 시작 부분으로 초기화
		Ma = *pb;	//가장 작은 변수를 저장할 Ma에 *pb 저장
		idxa = pa;	//포인터 초기화
		idxb = pb;	//포인터 초기화
		
		for(;pa<a+n;pa++){	//a 배열 탐색
			if(*pa<Ma){		//기존 Ma보다 더 작은 수를 찾았다면
				Ma = *pa;	//작은 수 저장
				idxa = pa;	//해당 수의 위치 저장
				flag = 1;	//배열 체크용
			}
		}
		
		for(;pb<b+m;pb++){	//b 배열 탐색
			if(*pb<Ma){		//기존 Ma보다 더 작은 수를 찾았다면
				Ma = *pb;	//작은 수 저장
				idxb = pb;	//해당 수의 위치 저장
			}
		}
		
		if(flag==0){		//b배열에서 작은 수를 발견했다면
			temp = *i;		//temp에 *i 임시 저장
			*i = *idxb;		//b배열의 가장 작은 값을 *i에 저장
			*idxb = temp;	//*idxb에 임시 저장한 *i값 저장
		}
		else{				//a배열에서 작은 수를 발견했다면
			temp = *i;		//temp에 *i 임시 저장
			*i = *idxa;		//a배열의 가장 작은 값을 *i에 저장
			*idxa = temp;	//*idxa에 임시 저장한 *i값 저장
		}
		printf("%d ",*(i));	//정렬된 작은 값 출력
	}
	printf("\n");	//출력 예시용 줄띄움
	
	return 0;	//main 함수 종료
}