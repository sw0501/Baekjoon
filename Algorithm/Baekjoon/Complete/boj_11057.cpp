//점화식 이상하게 세워서 30분 날렸다...
//DP의 부분문제를 생각을 해서 세우자
#include<iostream>

using namespace std;

int N;
int DP[1001][10];

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	
	cin >> N;
	
	//DP 초기화
	for(int i=0;i<=10;i++){
		DP[0][i]=1;
	}
	
	//
	for(int i=1;i<N;i++){
		for(int j=0;j<10;j++){
			if(j==0)DP[i][j]=1;
			else DP[i][j] = DP[i][j-1]+DP[i-1][j]%10007;
		}
	}
	int ans = 0;
	for(int j=0;j<10;j++){
		ans+=DP[N-1][j]%10007;
	}
	//N=1일때
	if(N==1)cout << 10 << "\n";
	else if(N==0)cout << 0 << "\n";
	else cout << ans%10007 << "\n";

}

