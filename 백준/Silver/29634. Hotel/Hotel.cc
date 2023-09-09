#include<iostream>
#include<queue>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {

    char arr[30][30];
    int CK[30][30] = { 0, };

    int N, M;
    int cnt = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '*')CK[i][j] = 1;
        }
    }

    //탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '.' && CK[i][j] == 0) {
                queue<pair<int, int>>BFS;
                BFS.push({ i,j });
                CK[i][j] = 1;

                int temp = 1;
                while (!BFS.empty()) {
                    int x = BFS.front().first;
                    int y = BFS.front().second;

                    

                    BFS.pop();
                    for (int k = 0; k < 4; k++) {
                        int tx = x + dx[k];
                        int ty = y + dy[k];
                        if (tx >= 0 && ty >= 0 && tx < N && ty < M) {
                            if (CK[tx][ty] == 0) {
                                CK[tx][ty] = 1;
                                BFS.push({ tx,ty });
                                temp++;
                            }
                        }
                    }
                }
                cnt = (temp > cnt ? temp : cnt);
            }
        }
    }

    if (cnt == 0)cnt = -1;
    cout << cnt << "\n";

    return 0;
}