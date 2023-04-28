#include<iostream>
#include<list>

using namespace std;

int N, M;
int ck[2000] = { 0, };
list<int>f[2000];
int cnt = 1;
int flag = 0;

void DFS(int num) {
	if (cnt == 5) {
		flag = 1;
		return;
	}
	ck[num] = 1;
	
	for (auto it : f[num]) {
		if (ck[it] == 0) {
			cnt++;
			DFS(it);
			cnt--;
		}
	}

	ck[num] = 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		f[a].push_back(b);
		f[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		DFS(i);
		if (flag)break;
	}
	

	cout << flag << "\n";

	return 0;
}