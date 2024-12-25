#include <iostream>
#include <queue>

using namespace std;

char map[51][51] = { 0, };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct Pos {
    int x, y, d;
};

int ans = 0;

int main()
{
    // 코드를 작성해주세요
    int L, W;

    cin >> L >> W;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < W; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < W; j++) {
            //방문하지 않고 육지인 경우에
            if (map[i][j] == 'L') {
                queue<Pos>q;
                q.push({ i,j,1 });

                int visit[51][51] = { 0, };
                visit[i][j] = 1;

                while (!q.empty()) {
                    int x = q.front().x;
                    int y = q.front().y;
                    int d = q.front().d;

                    ans = (ans > d ? ans : d);

                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int tx = x + dx[k];
                        int ty = y + dy[k];

                        if (tx >= 0 && tx < L && ty >= 0 && ty < W) {
                            if (visit[tx][ty] == 0 && map[tx][ty] == 'L') {
                                visit[tx][ty] = d + 1;
                                q.push({ tx,ty,d + 1 });
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans-1 << "\n";

    return 0;
}