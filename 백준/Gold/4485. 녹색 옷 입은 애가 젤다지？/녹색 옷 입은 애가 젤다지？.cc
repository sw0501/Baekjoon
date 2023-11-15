#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int INF = 125 * 9;

int map[126][126] = { 0, };
int dist[126][126] = {0,};

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dijkstra(int N, pair<int, int> start) {

	//시작 거리 초기화
	dist[0][0] = map[0][0];

	priority_queue<pair<int, pair<int, int>>>pq;
	pq.push(make_pair(-map[0][0], make_pair(0, 0)));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
				int tcost = cost + map[tx][ty];
				if (tcost < dist[tx][ty]) {
					dist[tx][ty] = tcost;
					pq.push(make_pair(-dist[tx][ty], make_pair(tx, ty)));
				}
			}
		}

	}

	return dist[N - 1][N - 1];

}
int main() {

	int idx = 1;

	while (1) {
		int N;
		cin >> N;
		if (N == 0)break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = INF;
				cin >> map[i][j];
			}
		}

		cout << "Problem " << idx++ << ": " << dijkstra(N, {0,0}) << "\n";
	}

	return 0;
}