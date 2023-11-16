#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

int graph[51][51] = { 0, };

int INF = 2501;

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;
			graph[i][j] = INF;
		}

	}

	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) {
			break;
		}
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)continue;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int min_score = INF;
	queue<int>q;

	for (int i = 1; i <= N; i++) {
		int max_score = 0;
		for (int j = 1; j <= N; j++) {
			max_score = max(graph[i][j], max_score);
		}
		//더 낮은 점수가 나온 경우 큐 초기화
		if (min_score > max_score) {
			while (!q.empty()) {
				q.pop();
			}
			min_score = max_score;
			q.push(i);
		}
		else if (min_score == max_score) {
			q.push(i);
		}
	}
	
	cout << min_score << " " << q.size() << "\n";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}