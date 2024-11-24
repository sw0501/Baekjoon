#include<bits/stdc++.h>

using namespace std;

int N, M;

//방문할 수 있는 정점 목록
vector<int>place[1000001];

//방문 확인
int check[1000001] = { 0, };

vector<int> route;


void DFS_path(int cur, int pre) {

	for (int i = 0; i < place[cur].size(); i++) {
		int nxt = place[cur][i];

		if (nxt == pre) {
			continue;
		}

		DFS_path(nxt, cur);

		if (check[nxt] == 1) {
			check[cur] = 1;
		}
	}
}

void DFS(int cur, int pre) {
	route.push_back(cur);

	for (int i = 0; i < place[cur].size(); i++) {
		int nxt = place[cur][i];

		if (nxt == pre || !check[nxt]) {
			continue;
		}

		DFS(nxt, cur);
		route.push_back(cur);
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//장소 개수 입력
	cin >> N >> M;

	//방문할 장소 입력
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		check[num] = 1;
	}

	//경로 입력
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;

		place[u].push_back(v);
		place[v].push_back(u);
	}

	DFS_path(0,-1);
	DFS(0,-1);

	cout << route.size() - 1 << "\n";

	for (int i = 0; i < route.size(); i++) {
		cout << route[i] << " ";
	}


	return 0;
}