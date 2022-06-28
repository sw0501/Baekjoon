#include <bits/stdc++.h>

using namespace std;

void init();

int N;
int K;
long long DP[1002][1002] = {0,};

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	init();
	
	
	return 0;
}

void init(){
	
	cin >> N >> K;
	
	DP[0][0] = 1;
	for(int i=1;i<=N;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i){
				DP[i][j]=1;
			}
			else{
				DP[i][j] = (DP[i-1][j-1] + DP[i-1][j])%10007;
			}
		}
	}
	
	cout << DP[N][K] << "\n";
	
}
