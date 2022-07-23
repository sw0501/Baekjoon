#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int T;
int N, M;
int A, B;
long long int INF = 987654321;

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

		vector<pair<int, int>>v[801];

		cin >> N >> M;

		for (int i = 0; i <= N; i++) {
			d[i] = INF;
		}

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}

		cin >> A >> B;

		dijkstra(v, 1);

		long long int sA = d[A];
		long long int sB = d[B];

		for (int i = 0; i <= N; i++) {
			d[i] = INF;
		}

		dijkstra(v, A);

		long long int AB = d[B];

		for (int i = 0; i <= N; i++) {
			d[i] = INF;
		}

		dijkstra(v, N);

		long long int dA = d[A];
		long long int dB = d[B];

		//1 -> v1 -> v2 -> N, 	1 -> v2 -> v1 -> N
		long long int ans = min(sA + AB + dB, sB + AB + dA);
		
		if (ans >= INF) {
			ans = -1;
		}
		
		cout << ans << "\n";

	return 0;
}