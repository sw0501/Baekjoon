#include<iostream>
#include<queue>

using namespace std;

void BFS();

int arr[1000][1000] = { 0, };
int dist[1000][1000] = { 0, };

int x, y;
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

typedef struct st {
	int x;
	int y;
	int dist;
}ground;

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				dist[i][j] = -1;
			}
			else if (arr[i][j] == 2) {
				x = i;
				y = j;
				dist[i][j] = 0;
			}
			else if (arr[i][j] == 0) {
				dist[i][j] = 0;
			}
		}
	}

	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}


void BFS() {
	queue<ground>bfs;
	bfs.push({x,y,0});

	//큐가 빌 때까지 탐색
	while (!bfs.empty()) {
		ground temp = bfs.front();
		bfs.pop();
		//cout << temp.x << temp.y << "\n";
		for (int k = 0; k < 4; k++) {
			int tx = temp.x + dx[k];
			int ty = temp.y + dy[k];
			if (tx >= 0 && ty >= 0 && tx < n && ty < m) {
				//아직 탐색되지 않은 자리라면
				if (dist[tx][ty] == -1) {
					dist[tx][ty] = temp.dist + 1;
					bfs.push({ tx, ty, dist[tx][ty] });
				}
			}
		}
	}
}