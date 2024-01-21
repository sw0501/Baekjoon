#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge {
	int start, dest, cost;
};

char univ[1001] = { 0, };
int set[1001] = {0,};

//B의 개수가 
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

	if (n1 > n2)set[n2] = n1;
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
		cin >> univ[i];
		set[i] = i;
	}

	int start, dest, cost;
	for (int i = 1; i <= M; i++) {
		cin >> start >> dest >> cost;
		if (univ[start] == univ[dest])continue;
		v.push_back({ start,dest,cost });
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(v[i].start, v[i].dest)) {
			cnt++;
			ans += v[i].cost;
			unionParent(v[i].start, v[i].dest);
		}
		if (cnt == N - 1)break;
	}
    
	if (cnt != N - 1)ans = -1;
	cout << ans << "\n";

	return 0;
}