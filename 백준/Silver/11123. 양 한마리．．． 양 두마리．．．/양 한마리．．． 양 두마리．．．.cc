#include <iostream>
#include <queue>

using namespace std;

char grid[101][101];
int visit[101][101] = { 0, };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
    // 코드를 작성해주세요

    int T;
    cin >> T;

    queue<pair<int, int>>q;

    for (int t = 0; t < T; t++) {
        int H, W;
        int cnt = 0;

        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                visit[i][j] = 0;
                grid[i][j] = '.';
            }
        }

        cin >> H >> W;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                //방문하지 않은 양
                if (grid[i][j] == '#' && visit[i][j] == 0) {
                    visit[i][j] = 1;
                    cnt++;
                    q.push({ i,j });

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int tx = x + dx[k];
                            int ty = y + dy[k];

                            if (tx >= 0 && tx < H && ty >= 0 && ty < W) {
                                if (grid[tx][ty] == '#' && visit[tx][ty] == 0) {
                                    visit[tx][ty] = 1;
                                    q.push({ tx,ty });
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}