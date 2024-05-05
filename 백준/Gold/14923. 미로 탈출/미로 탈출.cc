#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<queue>

using namespace std;

struct Point {
	int x, y, m, cnt;
};

queue<Point> q;
int arr[1001][1001] = { 0, };
bool visit[1001][1001][2] = {0,};

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;


	Point start, end;

	cin >> start.x >> start.y;
	start.m = 1;
	start.cnt = 0;

	cin >> end.x >> end.y;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	q.push(start);

	visit[start.x][start.y][1] = 1;
	visit[start.x][start.y][0] = 1;

	int flag = 1;

	while (!q.empty()) {
		Point temp = q.front();
		q.pop();

		if (temp.x == end.x && temp.y == end.y) {
			cout << temp.cnt << "\n";
			flag = 0;
			break;
		}

		for (int k = 0; k < 4; k++) {
			int tx = temp.x + dx[k];
			int ty = temp.y + dy[k];

			if (tx >= 1 && tx <= N && ty >= 1 && ty <= M) {
				//방문하지 않은 구역 확인
				if (visit[tx][ty][temp.m] == 0) {
					//벽 통과가 가능한지 확인
					if (arr[tx][ty]==1 && temp.m == 1) {
						visit[tx][ty][temp.m] = 1;
						q.push({ tx,ty,0,temp.cnt + 1 });
					}
					else if (arr[tx][ty] == 0) {
						visit[tx][ty][temp.m] = 1;
						q.push({ tx,ty,temp.m,temp.cnt + 1 });
					}
				}
			}
		}
	}

	if(flag)cout << "-1" << "\n";

	return 0;
}