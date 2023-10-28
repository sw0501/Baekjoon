#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int Map[1000][1000] = { 0, };
bool CK[1000][1000][2] = {false,};

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


int main() {


	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			Map[i][j] = (int)(c - '0');
		}
	}

	if (N == 1 && M == 1) {
		cout << 1 << "\n";
		return 0;
	}

	queue<pair<pair<pair<int, int>, int>, bool>>q;

	q.push({ { {0,0}, 1 }, false });
	CK[0][0][0] = true;

	int answer = -1;

	while (!q.empty()) {
		int x = q.front().first.first.first;
		int y = q.front().first.first.second;
		int cnt = q.front().first.second;
		bool br = q.front().second;

		CK[x][y][(br==true?1:0)] = true;

		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			
			if (tx == N - 1 && ty == M - 1) {
				if (answer == -1) {
					answer = cnt + 1;
				}
				while (!q.empty()) {
					q.pop();
				}
				break;
			}

			//배열 밖 탐색 제외
			if (tx >= 0 && tx < N && ty >= 0 && ty < M) {

				//아직 벽을 부시지 않은 상태에서 벽을 만난 경우
				if (Map[tx][ty] == 1 && !br) {
					CK[tx][ty][1] = true;
					q.push({ { {tx,ty},cnt + 1 },true });
				}
				//경로를 찾은 경우
				else if (Map[tx][ty] == 0 && !CK[tx][ty][(br==true?1:0)]) {
					CK[tx][ty][(br == true ? 1 : 0)] = true;
					q.push({ { {tx,ty},cnt + 1 },br });
				}
			}
		}
	}

	cout << answer << "\n";

	return 0;
}