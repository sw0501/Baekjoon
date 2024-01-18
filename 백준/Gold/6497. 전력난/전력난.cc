#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

struct Edge {
	int start, dest, cost;
};

int set[200001] = { 0, };
vector<Edge>v;

int getParent(int node) {
	if (node == set[node])return node;
	else return set[node] = getParent(set[node]);
}

int find(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);

	if (node1 == node2)return 1;
	else return 0;
}

void unionParent(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);

	if (node1 < node2)set[node2] = node1;
	else set[node1] = node2;
}

bool operator < (Edge& v1, Edge& v2) {
	return v1.cost < v2.cost;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		int M, N;
		cin >> M >> N;
		if (M == 0 && N == 0)break;
		for (int i = 0; i < M; i++) {
			set[i] = i;
		}

		int start, dest, cost;

		for (int i = 0; i < N; i++) {
			cin >> start >> dest >> cost;
			v.push_back({ start,dest,cost });
		}

		sort(v.begin(), v.end());

		int cnt = 0;
		int totalCost = 0;
		int TCost = 0;

		for (int i = 0; i < v.size(); i++) {
			TCost += v[i].cost;
			if (cnt != N - 1 && !find(v[i].start, v[i].dest)) {
				totalCost += v[i].cost;
				unionParent(v[i].start, v[i].dest);
				cnt++;
			}
		}

		cout << TCost - totalCost << "\n";
		v.clear();
	}

	return 0;
}