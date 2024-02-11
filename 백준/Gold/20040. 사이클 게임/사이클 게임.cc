#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

int N, M;

int set[500001] = { 0, };

int getParent(int a) {
	if (a == set[a]) return a;
	else {
		return set[a] = getParent(set[a]);
	}
}

void unionParent(int a,int b) {
	a = getParent(a);
	b = getParent(b);

	if (a > b) {
		set[b] = a;
	}
	else {
		set[a] = b;
	}
}

int find(int a,int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
}

void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		set[i] = i;
	}
	int a, b;
	int cnt = 2*M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (!find(a, b)) {
			unionParent(a, b);
		}
		else {
			cnt = (cnt < i + 1 ? cnt : i + 1);
		}
	}

	if (cnt == 2 * M) {
		cnt = 0;
	}
	cout << cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	return 0;
}