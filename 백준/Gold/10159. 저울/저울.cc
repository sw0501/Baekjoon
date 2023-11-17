#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

int graph[401][401];

int main() {

	int N,M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = -1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				//비교 결과를 알 수 있는 경우
				if (graph[i][k] == graph[k][j] && graph[i][k]!=0) {
					graph[i][j] = graph[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int cnt = N-1;
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] != 0)
				cnt--;
		}
		cout << cnt << "\n";
	}

	return 0;
}