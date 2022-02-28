#include<iostream>

using namespace std;

int dp[500][500];
int cp[500][500];
int answer = 0;

void init();
void cal(int n);

int main(){
	
	init();
	
	return 0;
}

void init(){
	int n;
	cin >> n;
	
	//정수 삼각형 입력
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cin >> cp[i][j];
		}
	}
	if(n==1){
		cout << cp[0][0] << "\n";
	}
	else cal(n);
	
}

void cal(int n){
	dp[0][0] = cp[0][0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			//0번째
			if(j==0){
				dp[i][j] = dp[i-1][j] + cp[i][j];
			}
			//i번째
			else if(j==i){
				dp[i][j] = dp[i-1][j-1] + cp[i][j];
			}
			//그 외
			else {
				dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + cp[i][j];
			}
			
			//cout << i << " " << j << " " << dp[i][j] << "\n";
			//마지막 열
			if(i==n-1){
				answer = max(answer,dp[i][j]);
			}
		}
		//cout << "\n";
	}
	cout << answer << "\n";
}