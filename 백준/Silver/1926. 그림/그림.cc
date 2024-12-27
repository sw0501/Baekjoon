#include <iostream>
#include <queue>

using namespace std;

int board[501][501] = { 0, };
bool visit[501][501];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
    // 코드를 작성해주세요

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] && !visit[i][j]) {
                cnt++;
                int temp = 1;
                queue<pair<int, int>>q;
                visit[i][j] = true;
                q.push({ i,j });

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;

                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int tx = x + dx[k];
                        int ty = y + dy[k];

                        if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
                            if (board[tx][ty] && !visit[tx][ty]) {
                                visit[tx][ty] = true;
                                temp++;
                                q.push({ tx,ty });
                            }
                        }
                    }
                }

                if (temp > ans) {
                    ans = temp;
                }
            }
        }
    }

    cout << cnt << "\n" << ans << "\n";
    return 0;
}
