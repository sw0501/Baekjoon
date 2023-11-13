#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M, K, X;
int d[300001] = { 0, };				//최단 경로
vector<pair<int, int>>v[300001];	//간선

int INF = 300000000;

void dijkstra(int start) {
	d[start] = 0;

	priority_queue<pair<int, int>>pq;	//힙
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;

		pq.pop();

		//기존 거리보다 긴 경우 스킵
		if (d[current] < distance)continue;
		
		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i].first;
			int nextDistance = distance + v[current][i].second;

			//더 저렴한 비용의 경로가 존재한다면 교체
			if(nextDistance < d[next]){
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> X;

	for (int i = 0; i <= N; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(make_pair(b, 1));
	}

	dijkstra(X);

	/*
	for (int i = 1; i <= N; i++) {
		cout << d[i] << "\n";
	}
	*/


	bool flag = false;
	for (int i = 1; i <= N; i++) {
		if (d[i] == K) {
			flag = true;
			cout << i << "\n";
		}
	}

	if (flag == false) {
		cout << "-1";
	}


	return 0;
}