#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
#include<limits.h>
#include<cmath>
#include<string>
#include<stack>

using namespace std;

int N, M, G, R;
int arr[50][50] = { 0, };

int groundCnt = 0;
vector<pair<int, int>> ground;



int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int answer = 0;

struct Water {
	int x, y;
	char c;
	int t;
};

Water green[5];
Water red[5];

void BFS() {
	int visit[50][50] = { 0, };
	int time[50][50] = { 0, };

	queue<Water>q;

	for (int i = 0; i < G; i++) {
		visit[green[i].x][green[i].y] = 1;
		time[green[i].x][green[i].y] = 1;
		q.push(green[i]);
	}
	for (int i = 0; i < R; i++) {
		visit[red[i].x][red[i].y] = 2;
		time[red[i].x][red[i].y] = 1;
		q.push(red[i]);
	}

	int cnt = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		char color = q.front().c;
		int t = q.front().t;
		int c = (q.front().c == 'g' ? 1 : 2);
		q.pop();

		//꽃이 핀 곳
		if (visit[x][y] == 3)continue;

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
				if (arr[tx][ty] == 0)continue;

				//첫 방문인 경우 표시
				//1 : green , 2 : red
				if (visit[tx][ty] == 0) {
					visit[tx][ty] = c;
					time[tx][ty] = t+1;
					q.push({ tx,ty, color ,t+1});
				}
				else {
					//배양액이 겹치고 
					if (visit[tx][ty] != 3 && visit[tx][ty] != c && time[tx][ty] == t+1) {
						visit[tx][ty] = 3;
						cnt++;
					}
				}
			}
		}
	}
	if (answer < cnt) {
		answer = cnt;
	}
}

void select(int g,int r, int idx) {
	if (g == G && r == R) {
		BFS();
		return;
	}
	for (int i = idx; i < groundCnt; i++) {
		if (g != G) {
			green[g] = { ground[i].first,ground[i].second,'g' ,1};
			select(g + 1, r, i + 1);
		}
		if (r != R) {
			red[r] = { ground[i].first,ground[i].second,'r' ,1};
			select(g, r + 1, i + 1);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> M >> G >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				ground.push_back({ i,j });
				groundCnt++;
			}
		}
	}

	select(0, 0, 0);

	cout << answer << "\n";

	return 0;
}