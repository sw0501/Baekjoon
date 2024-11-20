#include<bits/stdc++.h>

using namespace std;

int d[5001] = { 0, };
vector<pair<int, int>>city[5001];
int INF = INT_MAX;

void dijkstra(int start) {
	d[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	pq.push({ 0,start });

	while (!pq.empty()) {
		int current = pq.top().second;
		int dist = pq.top().first;

		pq.pop();

		if (d[current] >= dist) {
			for (int i = 0; i < city[current].size(); i++) {
				int next = city[current][i].first;
				int nextDist = dist + city[current][i].second;

				if (nextDist < d[next]) {
					d[next] = nextDist;
					pq.push({ nextDist,next });
				}
			}
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	int V, E, P;
	cin >> V >> E >> P;

	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a].push_back({ b,c });
		city[b].push_back({ a,c });
	}

	dijkstra(1);

	int dist = d[V];
	int distP = d[P];

	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}

	dijkstra(P);

	int distPV = d[V];

	if (dist == distP + distPV) {
		cout << "SAVE HIM" << "\n";
	}
	else {
		cout << "GOOD BYE" << "\n";
	}

	return 0;
}