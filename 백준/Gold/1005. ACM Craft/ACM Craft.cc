#include<iostream>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

int T;
int N, K;
int W;
queue<int>Q;

vector<int>v[100001];
int degree[1001] = { 0, };
int cost[1001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		int result[1001] = { 0, };
		
		cin >> N >> K;
		int temp = 0;
		for (int n = 1; n <= N; n++) {
			cin >> cost[n];
		}
		for (int k = 0; k < K; k++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			degree[b]++;
		}
		cin >> W;

		for (int i = 1; i <= N; i++) {
			if (degree[i] == 0) {
				Q.push(i);
				result[i] = cost[i];
			}
		}
		for (int i = 1; i <= N; i++) {
			int x = Q.front();
			Q.pop();
			for (int j = 0; j < v[x].size(); j++) {
				result[v[x][j]] = max(result[v[x][j]], result[x] + cost[v[x][j]]);
				if (--degree[v[x][j]] == 0) {
					Q.push(v[x][j]);
				}
			}
		}
		cout << result[W] << "\n";
		
		for (int i = 0; i < 100001; i++) {
			v[i].clear();
		}
	}

	return 0;
}