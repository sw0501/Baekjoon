#include<iostream>

using namespace std;

int N;
long long DP[90];

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	DP[0] = 1;
	DP[1] = 1;
	for(int i=2;i<N;i++){
		DP[i] = DP[i-1] + DP[i-2];
	}
	cout << DP[N-1] << "\n";
}

//피보나치 형태
// 1
// 10
// 101 100
// 1010 1001 1000
// 10100 10101 10010 10001 10000
// 101001 101000 101010 100100 100101 100010 100000 100001