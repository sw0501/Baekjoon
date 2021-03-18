#include<iostream>
#include<algorithm>

using namespace std;

int N; 		//수의 개수
int *num; 	//숫자 배열
int op[4]; 	//연산자 개수 [+,-,*,/]
int sum=0; 	//총합
int *oper;	//연산자 순서 배열
char *Op; 	//연산자 배열
int M;		//최대
int m;		//최소
int temp=1; //첫 입력 확인

void init();
void ac(int n);	//배열 생성
void Sum();		//계산

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	//입력
	cin >> N;
	num = new int[N];
	oper = new int [N-1];
	Op = new char[N-1];
	for(int i=0;i<N;i++){
		cin >> num[i];
	}
	int temp_op=0;
	//연산자 배열에 저장
	for(int i=0;i<4;i++){
		cin >> op[i];
		for(int j=0;j<op[i];j++){
			if(i==0)Op[temp_op++]='+';
			else if(i==1)Op[temp_op++]='-';
			else if(i==2)Op[temp_op++]='*';
			else Op[temp_op++]='/';
		}
	}
	
	//재귀로 숫자배열 만들기
	ac(0);
	cout << M << "\n" << m << "\n";
}

void ac(int n){
	//숫자 배열 만들기
	for(int i=0;i<N-1;i++){
		int flag=1;
		//겹치는 지 확인
		for(int j=0;j<n;j++){
			if(i==oper[j]){
				flag=0;
				break;
			}
		}
		//겹치는 숫자가 없다면 연산자 배열에 i 저장
		if(flag){
			oper[n]=i;
			
			//마지막까지 왔다면 계산후 결과값 비교후 연산자 배열 초기화
			if(n==N-2){
				Sum();
				oper[n]=-1;
			}
			//아니라면 재귀
			else ac(n+1);
		}
	}
	
	
}

void Sum(){
	sum=num[0];
	//계산
	for(int i=0;i<N-1;i++){
		if(Op[oper[i]]=='+')sum+=num[i+1];			// +
		else if(Op[oper[i]]=='-')sum-=num[i+1];	// -
		else if(Op[oper[i]]=='*')sum*=num[i+1];	// *
		else sum/=num[i+1];					// /
	}
	//비어있는 경우
	if(temp){
		temp=0;
		M=sum;
		m=sum;
	}
	//아니라면 비교하여 넣어줌
	else {
		if(sum>M)M=sum;
		if(m>sum)m=sum;
	}
}
