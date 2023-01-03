#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int Grape[10000]={0,};	//포도주 양
int DP[10000][3];		//DP (0 : 1칸 이동, 1 : 2칸 이동)

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> Grape[i];
	}
	
	DP[0][0] = Grape[0];
	DP[1][0] = DP[0][0] + Grape[1];
	DP[1][1] = Grape[1];
	DP[2][0] = DP[1][1] + Grape[2];
	DP[2][1] = DP[0][0] + Grape[2];
	DP[2][2] = Grape[2];
	
	for(int i=3;i<N;i++){
		for(int j=0;j<3;j++){
			//1칸 이동
			if(j==0){
				DP[i][j] = max(DP[i-1][1],DP[i-1][2]) + Grape[i];
			}
			//2칸 이동
			else if(j==1){
				DP[i][j] = max(DP[i-2][0],max(DP[i-2][1],DP[i-2][2])) + Grape[i];
			}
			//3칸 이동
			else {
				DP[i][j] = max(DP[i-3][0],max(DP[i-3][1],DP[i-3][2])) + Grape[i];
			}
		}
	}
	cout << max(DP[N-1][0],max(DP[N-1][1],DP[N-2][0])) << "\n";
}
