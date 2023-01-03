#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int V, E;
typedef struct edge {
	int start, dest, cost;
}Edge;
vector<Edge>v;
int CK[10001] = { 0, };
int set[10001];


int getParent(int set[], int x) {
	if (set[x] == x)return x;
	return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);

	if (a < b)set[b] = a;
	else set[a] = b;
}

int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b)return 1;
	else return 0;
}

bool operator <(Edge a,Edge b) {
	return a.cost < b.cost;
}

int main() {

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i <= V; i++) {
		set[i] = i;
	}
	
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(set, v[i].start, v[i].dest)) {
			sum += v[i].cost;
			unionParent(set, v[i].start, v[i].dest);
		}
	}

	cout << sum << "\n";

	return 0;
}