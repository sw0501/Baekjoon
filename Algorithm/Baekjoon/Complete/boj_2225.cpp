#include<iostream>
#include<algorithm>

using namespace std;

int N,K;
long long DP[201][201];	//DP[K][N]

void init();
void AD();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> K;
	
	//초기값 입력
	for(int i=0;i<=K;i++){
		DP[i][0]=1;
	}
	for(int j=0;j<=N;j++){
		DP[1][j]=1;
	}
	
	//점화식 DP[i][j] = DP[i][j-1] + DP[i-1][j];
	
	//DP를 이용하여 목표값 계산
	AD();
	
}

void AD(){
	for(int i=2;i<=K;i++){
		for(int j=1;j<=N;j++){
			DP[i][j] = DP[i-1][j] + DP[i][j-1];
			DP[i][j]%=1000000000;
		}
	}
	
	/*
	for(int i=1;i<=K;i++){
		for(int j=0;j<=N;j++){
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	if(N==1)cout << K << "\n";
	else if(K==1)cout << "1" << "\n";
	else cout << DP[K][N];
}