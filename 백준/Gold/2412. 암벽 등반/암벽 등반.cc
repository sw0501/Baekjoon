#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

int N, T;

struct Matrix {
	int x, y;
};


Matrix arr[50001];
int visit[50001] = { 0, };
unordered_map<int,unordered_map<int,int>>m;


struct Point {
	int x, y, cnt;
};

void BFS() {
	queue<Point>q;

	q.push({ 0,0,0 });
	
	while (!q.empty()) {
		Point p = q.front();
		q.pop();

		if (p.y == T) {
			cout << p.cnt << "\n";
			return;
		}

		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {
				if (p.x + i >= 0 && p.x + i <= 1000000 && p.y + j >= 0 && p.y + j <= 200000) {
					if (m[p.x + i].find(p.y+j)!= m[p.x + i].end() && visit[m[p.x + i][p.y+j]]==0 ) {
						visit[m[p.x + i][p.y + j]] = 1;
						q.push({ p.x + i,p.y + j,p.cnt + 1 });
					}
				}
			}
		}
	}

	cout << "-1" << "\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].x >> arr[i].y;
		
		if (m.find(arr[i].x) == m.end()) {
			unordered_map<int, int>temp;
			m.insert({ arr[i].x,temp });
		}

		m[arr[i].x].insert({ arr[i].y,i });
	}

	BFS();

	return 0;
}