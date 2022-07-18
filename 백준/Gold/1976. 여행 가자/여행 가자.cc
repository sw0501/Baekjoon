#include<iostream>

using namespace std;

int N, M;

int set[1000001];

int getParent(int x) {
	if (set[x] == x)return x;
	else return set[x] = getParent(set[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		set[b] = a;
	}
	else {
		set[a] = b;
	}
}

int find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b)return 1;
	else return 0;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		set[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			if (i != j&&num) {
				unionParent(i, j);
			}
		}
	}

	int m = -1;

	for (int i = 1; i <= M; i++) {
		int num;
		cin >> num;
		if (m == -1)m = getParent(num);
		else {
			if (m != getParent(num)) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";

	return 0;
}