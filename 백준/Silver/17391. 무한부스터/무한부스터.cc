#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
#include<limits.h>
#include<cmath>
#include<string>
#include<stack>
#include<unordered_map>


using namespace std;

int arr[301][301] = { 0, };
int visit[301][301] = { 0, };

struct Point{
	int x, y, boost, cnt;
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	queue<Point> q;

	visit[0][0] = 1;
	q.push({ 0,0,arr[0][0],1 });

	while (!q.empty()) {
		Point p = q.front();
		q.pop();

		if (p.x == N - 1 && p.y == M - 1) {
			cout << p.cnt - 1 << "\n";
			break;
		}

		for (int i = 1; i <= p.boost && p.x + i < N; i++) {
			if (!visit[p.x + i][p.y]) {
				visit[p.x + i][p.y] = 1;
				q.push({ p.x + i,p.y,arr[p.x + i][p.y],p.cnt + 1 });
			}
		}

		for (int i = 1; i <= p.boost && p.y + i < M; i++) {
			if (!visit[p.x][p.y + i]) {
				visit[p.x][p.y + i] = 1;
				q.push({ p.x,p.y + i,arr[p.x][p.y + i] ,p.cnt + 1 });
			}
		}
	}

	return 0;
}