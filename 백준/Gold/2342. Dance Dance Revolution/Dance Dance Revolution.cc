#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>

using namespace std;

//단계 / 왼발 위치 / 오른발 위치
int DP[100001][5][5] = {0,};
int num[100001] = { 0, };
int INF = INT_MAX;

int N;

int cost[5][5] = {
	{1, 2,2,2,2},
	{0,1,3,4,3},
	{0,3,1,3,4},
	{0,4,3,1,3},
	{0,3,4,3,1},
};

int DFS(int cnt, int left, int right) {
	if (cnt == N)return 0;
	if (DP[cnt][left][right] != 0) {
		return DP[cnt][left][right];
	}
	else {
		return DP[cnt][left][right] =
			min(
				DFS(cnt + 1,num[cnt] ,right) + cost[left][num[cnt]],
				DFS(cnt + 1,left,num[cnt]) + cost[right][num[cnt]]
			);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i = 0;
	while (1) {
		cin >> num[i];
		if (num[i++] == 0)break;
	}

	N = i;
	
	cout << DFS(0, 0, 0);
	
	return 0;
}