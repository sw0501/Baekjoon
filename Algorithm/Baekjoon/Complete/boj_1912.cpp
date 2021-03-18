#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int DP[100000]={0,};	//DP에 입력값 저장
int ans;				//최댓값 저장
void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> DP[i];
	}
	//첫 시작점
	ans = DP[0];
	for(int i=1;i<N;i++){
		//전에 있는 연속합이 나보다 작다면 더하는 것이 손해이므로 큰 수 저장
		DP[i] = max(DP[i],DP[i]+DP[i-1]);
		//값 비교하여 가장 큰 연속합 저장
		ans = max(ans,DP[i]);
	}
	cout << ans;
}
