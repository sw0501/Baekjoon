#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int A, B;
int INF = 100000001;

vector<pair<int, int>>city[1001];
int d[1001];			//거리

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>>pq;	//힙 구조
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int current = pq.top().first;
		//짧은 것이 먼저 오도록 음수화.
		int distance = -pq.top().second;
		pq.pop();
		//최단거리가 아니면 스킵
		if (d[current] < distance)continue;
		for (int i = 0; i < city[current].size(); i++) {
			//선택된 노드의 인접 노드
			int next = city[current][i].first;
			//선택된 노드를 인접 노드를 거쳐서 가는 비용
			int nextDistance = distance + city[current][i].second;
			//기존의 최소 비용보다 더 저렴하다면 교체
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a].push_back({ b,c });
	}
	cin >> A >> B;

	dijkstra(A);

	cout << d[B] << "\n";

	return 0;
}