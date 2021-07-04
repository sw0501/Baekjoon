#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int N,K;
int WV[101][2];
int DP[101][100001]={0,};	//DP[N][K] -> 동일한 무게에 최대가치만 저장하고 마지막에 가장 큰 가치를 계산

void init();


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> K;
	
	for(int i=1;i<=N;i++){
		cin >> WV[i][0] >> WV[i][1];
	}
		
	//시간 복잡도 : O(n^2)
	for(int i=1;i<=N;i++){
		for(int j=1;j<=K;j++){
			int w = WV[i][0];
			int v = WV[i][1];
			
			//더 담을 수가 없는 경우
			if(w>j){
				DP[i][j] = DP[i-1][j];
			}
			//더 담을 수 있는 경우
			else{
				//담기 전의 무게를 비교하여 더 큰 경우를 저장한다.
				DP[i][j] = max(DP[i-1][j],v+DP[i-1][j-w]);
			}
			//cout << DP[i][j] << " ";
		}
		//cout << "\n";
	}
	
	cout << DP[N][K] << "\n";
}



