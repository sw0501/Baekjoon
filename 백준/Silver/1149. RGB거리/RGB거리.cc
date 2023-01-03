#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;				//집의 개수
int H[1000][3];		//비용
int dp_R[1000];	//Red
int dp_G[1000];	//Green
int dp_B[1000];	//Blue

void init();

int main(){
	
	init();
	
	return 0;
}

//위에 2개 중에 작은 것 dp로 계속 더함
// 1 1 1
// 2 2 2
// 3 3 3

void init(){
	cin >> N;
	//집 비용 입력
	for(int i=0;i<N;i++){
		cin >> H[i][0] >> H[i][1] >> H[i][2];
	}
	
	//첫번째 DP 계산
	dp_R[0] = H[0][0];
	dp_G[0] = H[0][1];
	dp_B[0] = H[0][2];
	
	//DP 계산
	for(int i=1;i<N;i++){
		//상위 차수의 선택 가능한 DP 중 작은 값과 자신을 합한 값을 DP에 저장
		dp_R[i] = min(dp_G[i-1],dp_B[i-1])+H[i][0];
		dp_G[i] = min(dp_R[i-1],dp_B[i-1])+H[i][1];
		dp_B[i] = min(dp_R[i-1],dp_G[i-1])+H[i][2];
	}
	
	if(dp_R[N-1]<=dp_G[N-1]&&dp_R[N-1]<=dp_B[N-1])cout << dp_R[N-1];
	else if(dp_G[N-1]<=dp_R[N-1]&&dp_G[N-1]<=dp_B[N-1])cout << dp_G[N-1];
	else cout << dp_B[N-1];
	
}
