#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>

using namespace std;

int N, M;

struct planet {
	int x, y;
};

typedef struct edge {
	int start, dest;
	double cost;
}Edge;

vector<Edge>v;
vector<planet>p;

int set[10001];

//사이클 생성 여부 확인

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

bool operator < (Edge a, Edge b) {
	return a.cost < b.cost;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	p.push_back({ -1,-1 });

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		p.push_back({ a,b });
	}

	for (int i = 0; i <= N; i++) {
		set[i] = i;
	}

	double sum = 0;

	int cnt = 0;
	//Uni
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (!find(set, a, b)) {
			cnt++;
			unionParent(set, a, b);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			double dist = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
			v.push_back({ i,j,dist });
		}
	}

	sort(v.begin(), v.end());

	/*
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].start << " " << v[i].dest << " " << v[i].cost << "\n";
	}
	*/

	for (int i = 0; i < v.size(); i++) {
		//사이클이 생성되지 않는다면
		if (!find(set, v[i].start, v[i].dest)) {
			sum += v[i].cost;
			unionParent(set, v[i].start, v[i].dest);
			cnt++;
			if (cnt == N - 1) {
				break;
			}
		}
	}

	printf("%.2lf", sum);

	return 0;
}