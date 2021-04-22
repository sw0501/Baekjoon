//문제가 너무 큰 수면 브루트포스말고 다른 방법을 찾아보자 
//ex) 뒷자리 0의 개수는 2의 개수 와 5의 개수중 작은 것
#include<iostream>
#include<algorithm>

using namespace std;

long long n;
long long m;
long long C2=0;
long long C5=0;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	
	
	//nCr 의 뒷자리 0의 개수는 2와 5의 개수 중 적은 수   2*5 = 10이므로 더 적은 쪽이 0의 자리 개수이다.
	cin >> n >> m;
	
	//n!, (n-m)!, m!에서 2,5의 개수를 세주고 그중 적은 수가 답
	//n! - (n-m)! - m!
	for(int i=2;i<=n;i*=2){
		C2 += n/i;
	}
	for(int i=2;i<=m;i*=2){
		C2 -= m/i;
	}
	for(int i=2;i<=n-m;i*=2){
		C2 -= (n-m)/i;
	}
	for(int i=5;i<=n;i*=5){
		C5 += n/i;
	}
	for(int i=5;i<=m;i*=5){
		C5 -= m/i;
	}
	for(int i=5;i<=n-m;i*=5){
		C5 -= (n-m)/i;
	}
	
	cout << (C2>C5?C5:C2) << "\n";
	
}

