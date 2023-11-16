#include<iostream>
#include<cmath>

using namespace std;

int graph[401][401] = { 0, };
int dist[401] = { 0, };

int INF = 16000000;
int main() {

	int V, E;
	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j)continue;
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < E; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		graph[a][b] = d;
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (i == j)continue;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			//사이클이 생기는 경우 ans에 최솟값 비교하여 저장
			if (i == j || graph[i][j] == INF)continue;
			ans = min(ans, graph[i][j] + graph[j][i]);
		}
	}

	if (ans == INF) {
		cout << -1;
	}
	else cout << ans << "\n";
	return 0;
}