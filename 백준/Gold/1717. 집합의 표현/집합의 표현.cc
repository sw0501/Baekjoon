#include<iostream>

using namespace std;

int N, M;

int set[1000001];

int getParent(int x) {
	if (set[x] == x)return x;
	else return set[x] = getParent(set[x]);
}

void unionParent(int a,int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		set[b] = a;
	}
	else {
		set[a] = b;
	}
}

int find(int a,int b) {
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

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			if (find(b, c)){
				cout << "YES" << "\n";
			}
			else cout << "NO" << "\n";
		}
		else {
			unionParent(b, c);
		}
	}




	return 0;
}