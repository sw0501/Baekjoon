#include <bits/stdc++.h>

using namespace std;

int room[21][21] = { 0, };
int N;
int student[401][401] = { 0, };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<int>q;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int num;
		cin >> num;
		q.push(num);
		for (int j = 0; j < 4; j++) {
			int f;
			cin >> f;
			student[num][f] = 1;
		}
	}

	while (!q.empty()) {

		int num = q.front();
		q.pop();

		int satisfy = -1;
		int empty = 0;
		int x = 0;
		int y = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				//이미 있는 칸은 패스
				if (room[i][j])continue;

				int tempEmpty = 0;
				int tempSatis = 0;

				for (int k = 0; k < 4; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];

					
					if (tx >= 1 && tx <= N && ty >= 1 && ty <= N) {
						if (room[tx][ty]) {
							//좋아하는 학생 있는 경우
							if (student[num][room[tx][ty]]) {
								tempSatis++;
							}
						}
						//빈 경우
						else {
							tempEmpty++;
						}
					}
				}

				//조건 1
				if (satisfy < tempSatis) {
					x = i;
					y = j;
					satisfy = tempSatis;
					empty = tempEmpty;
				}
				else if (satisfy == tempSatis) {
					if (empty < tempEmpty) {
						x = i;
						y = j;
						satisfy = tempSatis;
						empty = tempEmpty;
					}
				}
			}
		}

		room[x][y] = num;
	}
	
	int answer = 0;
	for (int i = 1 ; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int tx = i + dx[k];
				int ty = j + dy[k];
				if (tx >= 1 && tx <= N && ty >= 1 && ty <= N) {
					//좋아하는 학생 있는 경우
					if (student[room[i][j]][room[tx][ty]]) {
						cnt++;
					}
				}
			}

			switch (cnt) {
			case 0:
				answer += 0;
				break;
			case 1:
				answer += 1;
				break;
			case 2:
				answer += 10;
				break;
			case 3:
				answer += 100;
				break;
			case 4:
				answer += 1000;
				break;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}