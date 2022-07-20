#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int set[1001];

struct graph {
	int a, b, cost;
};

vector<graph>v;

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

int find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b)return 1;
	else return 0;
}

bool compare(graph a, graph b) {
	return a.cost < b.cost;
}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		set[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int c;
			cin >> c;
			if (i == j)continue;
			v.push_back({ i,j,c });
		}
	}

	sort(v.begin(), v.end(), compare);

	/*
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].cost << "\n";
	}
	*/

	long long int cost = 0;
	
	for (int i = 0; i < v.size(); i++) {
		if (!find(v[i].a,v[i].b)) {
			cost += v[i].cost;
			unionParent(v[i].a, v[i].b);
		}
	}


	cout << cost << "\n";

	return 0;
}

