#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge {
	int start, dest, cost;
};

int set[10001] = {0,};
int countryCost[10001] = { 0, };

vector<Edge>v;

int getParent(int node) {
	if (node == set[node]) {
		return node;
	}
	else return set[node] = getParent(set[node]);
}

int find(int n1, int n2) {
	n1 = getParent(n1);
	n2 = getParent(n2);

	if (n1 == n2)return 1;
	else return 0;
}

void unionParent(int n1, int n2) {
	n1 = getParent(n1);
	n2 = getParent(n2);

	//방문 비용이 낮은 쪽을 루트로 구성
	if (countryCost[n1] < countryCost[n2])set[n2] = n1;
	else set[n1] = n2;
}

bool operator < (Edge& a, Edge& b) {
	return a.cost < b.cost;
}



int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> countryCost[i];
		set[i] = i;
	}

	int cnt = 0;

	int start, dest, cost;

	for (int i = 1; i <= M; i++) {
		cin >> start >> dest >> cost;
		//출발지와 도착지의 방문 비용을 포함한 MST 구성
		v.push_back({ start,dest,2*cost+countryCost[dest] + countryCost[start]});
	}

	sort(v.begin(), v.end());
	
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(v[i].start, v[i].dest)) {
			//cout << v[i].start << " " << v[i].dest << "\n";
			cnt++;
			unionParent(v[i].start, v[i].dest);
			ans += v[i].cost;
		}
		if (cnt == N - 1)break;
	}

	//루트 노드 방문 비용 추가
	for (int i = 1; i <= N; i++) {
		if (set[i] == i) {
			ans += countryCost[i];
		}
	}

	cout << ans << "\n";

	return 0;
}
