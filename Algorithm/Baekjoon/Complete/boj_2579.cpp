#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;					//계단 갯수
int stair[300];			//계단 점수
int dp[300][2]={0,};	//각 층 계단에 도착했을 때 큰 것만 계산, 마지막은 연속 2번일 경우 확인

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> stair[i];
	}
	
	//각 계단을 밟을때마다 dp에 저장 0=1칸 1=2칸 2=연속
	dp[0][0] = stair[0];			//1칸 이동
	dp[1][0] = dp[0][0] + stair[1];	//1칸 이동
	dp[1][1] = stair[1];			//2칸 이동
	
	//아래층의 경우를 비교하여 DP에 저장
	for(int i=2;i<n;i++){
		for(int j=0;j<2;j++){
			//1칸 이동
			if(j==0){
				dp[i][j] = dp[i-1][1] + stair[i];
			}
			//2칸 이동
			else if(j==1){
				dp[i][j] = max(dp[i-2][0],dp[i-2][1]) + stair[i];
			}
		}	
	}
	
	cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
	
}
