#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, X;
int INF = 987654321;

vector<pair<int, int>>city[1001];
int d[1001];			//거리
int T[1001] = { 0, };	//시간 총합

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;	//힙 구조
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		//최단거리가 아니면 스킵
		if (d[current] >= distance) {
			for (int i = 0; i < city[current].size(); i++) {
				//선택된 노드의 인접 노드
				int next = city[current][i].first;
				//선택된 노드를 인접 노드를 거쳐서 가는 비용
				int nextDistance = distance + city[current][i].second;
				//기존의 최소 비용보다 더 저렴하다면 교체
				if (nextDistance < d[next]) {
					d[next] = nextDistance;
					pq.push(make_pair(nextDistance, next));
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;

	for (int i = 0; i <= N; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a].push_back({ b,c });
	}

	dijkstra(X);

	for (int i = 1; i <= N; i++) {
		T[i] = d[i];
	}

	int M = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			d[j] = INF;
		}
		dijkstra(i);
		T[i] += d[X];
		if (T[i] > M)M = T[i];
	}

	cout << M << "\n";

	return 0;
}