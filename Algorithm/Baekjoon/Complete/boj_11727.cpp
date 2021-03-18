#include<iostream>

using namespace std;

int N;
long long DP[1001]={0,};	//[idx]까지 도달하는 동안 가능한 경우의 수를 저장

void init();

int main(){
	
	init();

	return 0;
	
}

void init(){
	cin >> N;
	DP[0]=1;
	DP[1]=3;
	for(int i=2;i<N;i++){
		DP[i]=DP[i-1]+2*DP[i-2];
		DP[i]%=10007;
	}
	cout << DP[N-1] << "\n";
}


//알고 풀어야하는데 그냥 규칙을 찾아서 풀어버렷네...
