#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>

using namespace std;

int matrix[501][2] = { 0, };
int DP[501][501] = {0,};

//DP[i][j] : i부터 j까지 행렬 곱을 진행했을 때 최솟값

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> matrix[i][0] >> matrix[i][1];
	}

	//i : 범위
	for (int i = 1; i < N; i++) {
		//시작 행렬 번호
		for (int j = 1; i + j <= N; j++) {
			DP[j][i + j] = INT_MAX;
			//중간 행렬 번호
			for (int k = j; k <= i + j; k++) {
				DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k+1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
			}
		}
	}

	cout << DP[1][N];

	return 0;
}