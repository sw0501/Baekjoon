//피보나치수열과 비슷한 문제 대신 P(n) = P(n-3) + P(n-4)으로 풀어야함
#include<iostream>
#include<algorithm>

using namespace std;

int T;		//테스트 케이스 개수
int N;		//입력 
long long m2 = 1; //메모이제이션 2
long long m3 = 1; //메모이제이션 3
long long m4 = 0; //메모이제이션 4
int n = 3;	//반복 횟수

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> T;
	for(int i=0;i<T;i++){
		cin >> N;
		//예외처리
		if(N==1||N==2){
			cout << 1 << "\n";
		}
		else {
			//점화식 P(n) = P(n-3) + P(n-4) 를 이용하기 위해 메모이제이션 4개 필요
			while(1){
				long long temp = m3 + m4;
				m4 = m3;
				m3 = m2;
				m2 = temp;
				if(n==N){
					cout << m2 << "\n";
					break;
				}
				n++;
			}
			//사용한 변수 초기화
			m2 = 1;
			m3 = 1;
			m4 = 0;
			n = 3;
		}
	
	}
}
