//들어갈 자료의 크기보고 적당한 자료형을 쓰자 ex) 매우매우 큰 정수형 -> long long
#include<iostream>
#include<algorithm>

using namespace std;

int N;		//테스트 케이스
int M;		//구할 피보나치 수열
int f1=0;	//1번 수
int f2=0;	//2번 수
int num=0;	//피보나치 수열

void init();
void Fibo(int n);

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> M;
		Fibo(0);
	}
}

void Fibo(int n){
	if(n==0){
		f1=1;
		f2=0;
	}
	else if(n==1){
		f1=0;
		f2=1;
	}
	else {
		int temp = f1+f2;
		f1 = f2;
		f2 = temp;
	}
	if(n==M){
		cout<<f1<<" "<<f2<<"\n";
		return;
	}
	Fibo(n+1);
}
