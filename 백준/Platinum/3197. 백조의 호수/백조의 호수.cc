#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

char arr[1500][1500] = { 0 };
int set[4000001] = { 0 };

int getParent(int x) {
	if (x == set[x])return x;
	else return set[x] = getParent(set[x]);
}

int find(int a,int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b)return 1;
	else return 0;
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a > b)set[a] = b;
	else set[b] = a;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int R, C;
	cin >> R >> C;

	int L1 = -1;
	int L2 = -1;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			set[i * C + j] = -1;
		}
	}

	queue<pair<int, int>>ice;
	queue<pair<int, int>> wait;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (set[i * C + j] == -1 && (arr[i][j]=='.' || arr[i][j]=='L')) {
				int idx = i * C + j;
				set[i * C + j] = idx;

				queue<pair<int, int>>q;
				q.push({ i,j });

				while (!q.empty()) {
					
					int x = q.front().first;
					int y = q.front().second;

					if (arr[x][y] == 'L') {
						if (L1 == -1) {
							L1 = x * C + y;
						}
						else {
							L2 = x * C + y;
						}
					}

					q.pop();

					for (int k = 0; k < 4; k++) {
						int tx = x + dx[k];
						int ty = y + dy[k];
						if (tx >= 0 && tx < R && ty >= 0 && ty < C) {
							if (set[tx * C + ty] == -1) {
								set[tx * C + ty] = idx;
								//빙판인 경우
								if (arr[tx][ty] == 'X') {
									wait.push({ tx,ty });
								}
								else {
									q.push({ tx,ty });
								}
							}
						}
					}
				}
			}
		}
	}


	if (find(L1, L2)) {
		cout << 0 << "\n";
		return 0;
	}

	while (!wait.empty()) {
		int x = wait.front().first;
		int y = wait.front().second;

		ice.push(wait.front());
		wait.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];

			//방문안한 빙판 녹이기
			if (tx >= 0 && tx < R && ty >= 0 && ty < C) {
				if (set[tx * C + ty] != -1) {
					unionParent(x * C + y, tx * C + ty);
				}
			}
		}
	}

	int cnt = 1;

	//같은 지역이 될 때까지
	while (!find(L1, L2)) {
		//cout << getParent(L1) << " " << getParent(L2) << "\n";
		//빙판 녹이기
		while (!ice.empty()) {
			int x = ice.front().first;
			int y = ice.front().second;

			ice.pop();

			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k];
				int ty = y + dy[k];

				//방문안한 빙판 녹이기
				if (tx >= 0 && tx < R && ty >= 0 && ty < C) {
					if (set[tx * C + ty] == -1) {
						
						if (arr[tx][ty] == 'X') {
							set[tx * C + ty] = x * C + y;
							wait.push({ tx,ty });
						}
					}
					else {
						unionParent(x * C + y, tx * C + ty);
					}
				}
			}
		}
			
		while (!wait.empty()) {
			int x = wait.front().first;
			int y = wait.front().second;

			ice.push(wait.front());
			wait.pop();

			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k];
				int ty = y + dy[k];

				//방문안한 빙판 녹이기
				if (tx >= 0 && tx < R && ty >= 0 && ty < C) {
					if (set[tx * C + ty] != -1) {
						unionParent(x* C + y, tx* C + ty);
					}
				}
			}
		}

		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}