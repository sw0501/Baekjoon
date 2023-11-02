#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int>parent(501, 0);

int  getParent(int x) {
	if (parent[x] == x)return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent( int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b)return 1;
	else return 0;
}

int main() {

	int idx = 1;
	while (1) {
		int N, M;
		cin >> N >> M;

		vector<int>cycle(N + 1,0);

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}

		if (N == 0 && M == 0) {
			return 0;
		}

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			
			

			int pa = getParent(a);
			int pb = getParent(b);
			if (pa == pb) {
				cycle[pa] = 1;
			}
			else {
				if (cycle[pa] || cycle[pb]) {
					cycle[pa] = 1;
					cycle[pb] = 1;
				}
				unionParent(a, b);
			}
			
		}

		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (parent[i] == i && cycle[i] == 0) {
				ans++;
			}
		}

		cout << "Case " << idx << ": ";
		if (ans == 0) {
			cout << "No trees.\n";
		}
		else if (ans == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << ans << " trees.\n";
		}

		idx++;
	}


	
	return 0;
}