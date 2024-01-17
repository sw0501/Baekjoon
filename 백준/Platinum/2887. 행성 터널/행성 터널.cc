#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

struct Planet{
	int idx;
	int x, y, z;
};

struct Edge {
	int start, dest, cost;
};

bool operator < (Edge &a, Edge&b){
	return a.cost<b.cost;
}

bool compareX(Planet& a, Planet& b) {
	return a.x < b.x;
}

bool compareY(Planet& a, Planet& b) {
	return a.y < b.y;
}

bool compareZ(Planet& a, Planet& b) {
	return a.z < b.z;
}

Planet p[100001] = { 0, };
int set[100001] = { 0, };
vector<Edge>v;

int getParent(int x) {
	if (x == set[x])return x;
	return set[x] = getParent(set[x]);
}

int find(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x == y)return 1;
	return 0;
}

void unionParent(int x,int y) {
	x = getParent(x);
	y = getParent(y);

	if (x < y)set[y] = x;
	else set[x] = y;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> p[i].x >> p[i].y >> p[i].z;
		p[i].idx = i;
		set[i] = i;
	}

	sort(p, p + N, compareX);

	for (int i = 0; i < N-1; i++) {
		int cost = min(abs(p[i].x - p[i+1].x), min(abs(p[i].y - p[i+1].y), abs(p[i].z - p[i+1].z)));
		v.push_back({ p[i].idx, p[i + 1].idx, cost });
	}

	sort(p, p + N, compareY);

	for (int i = 0; i < N - 1; i++) {
		int cost = min(abs(p[i].x - p[i + 1].x), min(abs(p[i].y - p[i + 1].y), abs(p[i].z - p[i + 1].z)));
		v.push_back({ p[i].idx, p[i + 1].idx, cost });
	}

	sort(p, p + N, compareZ);

	for (int i = 0; i < N - 1; i++) {
		int cost = min(abs(p[i].x - p[i + 1].x), min(abs(p[i].y - p[i + 1].y), abs(p[i].z - p[i + 1].z)));
		v.push_back({ p[i].idx, p[i + 1].idx, cost });
	}

	sort(v.begin(),v.end());

	int cnt = 0;
	int cost = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(v[i].start, v[i].dest)) {
			cnt++;
			cost += v[i].cost;
			unionParent(v[i].start, v[i].dest);
		}
	}

	cout << cost << "\n";

	return 0;
}