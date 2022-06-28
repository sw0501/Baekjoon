#include<iostream>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

int N, M;
int arr[1001][1001] = { 0, };
int CK[1000*1000+2] = { 0, };
queue<pair<int, int>>q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {

	cin >> N >> M;

	getchar();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch;
			cin >> ch;
			arr[i][j] = (int)(ch - '0');
		}
	}

	int Num = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				q.push({ i,j });
				arr[i][j] = Num;
				CK[Num]++;
				while (!q.empty()) {
					for (int k = 0; k < 4; k++) {
						int tx = q.front().first + dx[k];
						int ty = q.front().second + dy[k];
						if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
							continue;
						}
						else if (arr[tx][ty] == 0) {
							arr[tx][ty] = Num;
							CK[Num]++;
							q.push({ tx,ty });
						}
					}
					q.pop();
				}
				Num++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != 1)cout << "0";
			else {
				long long int C = 1;
				map<int, int>m;
				for (int k = 0; k < 4; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];
					if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
						continue;
					}
					else {
						if (arr[tx][ty] != 1&&m.find({arr[tx][ty]}) == m.end()) {
							C += CK[arr[tx][ty]];
							m.insert({ arr[tx][ty] ,1 });
						}
					}
				}
				cout << C%10;
			}
		}
		cout << "\n";
	}

	return 0;
}