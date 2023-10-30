#include<iostream>
#include<cmath>

using namespace std;

int INF = 1000000000;

int graph[101][101];
int item[101] = { 0, };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> item[i];
	}

	for (int i = 0; i < R; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a][b] = min(graph[a][b], c);
		graph[b][a] = min(graph[b][a], c);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		int temp_ans = 0;
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] <= M)temp_ans += item[j];
		}
		ans = (ans > temp_ans ? ans : temp_ans);
	}

	cout << ans << "\n";
	return 0;
}