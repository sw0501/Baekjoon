#include<iostream>
#include<algorithm>

using namespace std;

int T;
int N;
int AR[100000][2];	//배열 저장
int DP[100001][2];	//윗줄 선택, 아랫줄 선택, 선택안함 3가지 케이스로 나눠서 푼다

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> T;
	for(int k=0;k<T;k++){
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> AR[i][0];
		}
		for(int i=0;i<N;i++){
			cin >> AR[i][1];
		}
		
		//예외처리
		DP[0][0] = AR[0][0];
		DP[0][1] = AR[0][1];
		DP[1][0] = DP[0][1]+AR[1][0];
		DP[1][1] = DP[0][0]+AR[1][1];
								  
		//아무것도 선택하지 않았을 때 값과 전에 선택했던 값과 비교하여 더 큰 것을 저장
		for(int i=2;i<N;i++){
			DP[i][0] = max(DP[i-1][1],max(DP[i-2][0],DP[i-2][1]))+AR[i][0];
			DP[i][1] = max(DP[i-1][0],max(DP[i-2][0],DP[i-2][1]))+AR[i][1];
		}
		
		cout << max(DP[N-1][0],DP[N-1][1]) << "\n";
	}
}
