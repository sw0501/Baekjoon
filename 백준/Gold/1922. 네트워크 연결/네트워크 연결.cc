#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int set[1001];
int CK[1001] = { 0, };

typedef struct net {
	int start, dest, cost;
}Net;

vector<Net>v;

int getParent(int x) {
	if (set[x] == x)return x;
	else return set[x] = getParent(set[x]);
}

void unionParent(int a,int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b)set[b] = a;
	else set[a] = b;
}

int find(int a,int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b)return 1;
	else return 0;
}

bool compare(Net a, Net b) {
	return a.cost < b.cost;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		set[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b)continue;
		v.push_back({ a, b, c });
	}

	sort(v.begin(), v.end(),compare);

	int cost = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(v[i].start, v[i].dest)) {
			cost+=v[i].cost;
			unionParent(v[i].start, v[i].dest);
		}
	}

	cout << cost << "\n";

	return 0;
}