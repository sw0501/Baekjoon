//피보나치 수열...
//너무 큰 숫자를 할때는 오버플로우가 발생하니까 이점 유의해서 문제를 풀어야할듯
//인트로 푸는것도 가능함
//이걸 풀려면 문자열로 받아서 계산을 하던가 주어진 조건 참조
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;		//이진 수열 크기
long long m1 = 1;	//메모이제이션 1
long long m2 = 1; //메모이제이션 2
int n=2;	//반복 카운트

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> N;
	if(N==1){
		cout << m1 << "\n";
	}
	else {
		while(1){
			//오버플로우 방지를 위해 조건처럼 나눠준다
			long long temp = (m1+m2)%15746;
			m1 = m2;
			m2 = temp;
			if(n==N){
				cout << m2 << "\n";
				return ;
			}
			n++;
		}
	}
}
