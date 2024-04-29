#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>

using namespace std;

int memory[101] = { 0, };
int cost[101] = { 0, };
int DP[101][10001] = { 0, };	//1 ~ i번 배낭까지 고려했을 때 최대 가치

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> memory[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10001; j++) {
			if (cost[i] > j) {
				DP[i][j] = DP[i - 1][j];
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - cost[i]] + memory[i]);
			}
		}
	}

	for (int j = 0; j < 10001; j++) {
		if (DP[N][j] >= M) {
			cout << j << "\n";
			break;
		}
	}



	return 0;
}