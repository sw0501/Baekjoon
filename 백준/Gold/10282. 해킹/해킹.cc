#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int T;
int N, M, C;
long long int INF = 121110987654321;

long long int d[20010];			//거리

void dijkstra(vector<pair<int,int>>com[], int start) {
	d[start] = 0;
	priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>>pq;	//힙 구조
	pq.push(make_pair(0, start)); 
	while (!pq.empty()) {
		int current = pq.top().second;
		long long int distance = pq.top().first;
		pq.pop();
		//최단거리가 아니면 스킵
		if (d[current] >= distance) {
			for (int i = 0; i < com[current].size(); i++) {
				//선택된 노드의 인접 노드
				int next = com[current][i].first;
				//선택된 노드를 인접 노드를 거쳐서 가는 비용
				long long int nextDistance = distance + com[current][i].second;
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

	cin >> T;

	for (int t = 0; t < T; t++) {
		vector<pair<int, int>>v[20010];

		cin >> N >> M >> C;

		for (int i = 0; i <= N; i++) {
			d[i] = INF;
		}

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[b].push_back({ a,c });
		}

		dijkstra(v, C);

		int cnt = 0;
		long long int MT = 0;
		for (int i = 1; i <= N; i++) {
			if (d[i] != INF) {
				cnt++;
				if (d[i] > MT) {
					MT = d[i];
				}
			}
		}

		cout << cnt << " " << MT << "\n";

	}

	return 0;
}