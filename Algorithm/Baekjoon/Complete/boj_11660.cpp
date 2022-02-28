#include <bits/stdc++.h>

using namespace std;

void init();

int N,T;
int xy[100000][4];
int arr[1024][1024]={0,};
int DP[1025][1025] = {0,};
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> T;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> arr[j][i];
		}
	}
	
	for(int i=0;i<T;i++){
		for(int j=0;j<4;j++){
			cin >> xy[i][j];
		}
	}
	
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			DP[i][j] = DP[i][j-1] + arr[i-1][j-1];
			DP[i][j-1] += DP[i-1][j-1];
		}
		DP[i][N] += DP[i-1][N];
	}
	
	/*
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	for(int t=0;t<T;t++){
		cout << DP[xy[t][3]][xy[t][2]] + DP[xy[t][1]-1][xy[t][0]-1] - DP[xy[t][1]-1][xy[t][2]] - DP[xy[t][3]][xy[t][0]-1]<< "\n";
	}
}
