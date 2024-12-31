#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int map[51][51] = { 0, };

int N, M;

int cnt = 0;
int ans = 50 * 50;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<pair<int, int>> v(11);

void search(int x, int y, int c) {
    if (c == M) {
        int temp = 0;
        int minT = 0;

        int visit[51][51] = { 0, };

        queue<pair<int,pair<int, int>>>q;

        for (int k = 0; k < M; k++) {
            q.push({ 0,v[k] });
            visit[v[k].first][v[k].second] = 1;
        }

        while (!q.empty()) {
            int t = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;

            q.pop();
            minT = t;

            for (int k = 0; k < 4; k++) {
                int tx = x + dx[k];
                int ty = y + dy[k];

                if (tx >= 0 && tx < N && ty >= 0 &&ty < N) {
                    if (map[tx][ty] == 1 || visit[tx][ty])continue;
                    visit[tx][ty] = t + 1;

                    if (map[tx][ty] == 2) {
                        q.push({ t + 1,{tx,ty} });
                    }
                    else {
                        q.push({ t + 1,{tx,ty} });
                        temp++;
                        if (temp == cnt) {
                            ans = (ans < minT ? ans : minT);
                        }
                    }
                }
            }
        }

        if (temp==cnt) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    minT = (minT < visit[i][j] ? visit[i][j] : minT);
                }
            }

            ans = (ans < minT ? ans : minT);
        }
        

        return;
    }
    
    for (int i = x; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == x && j == 0) j = y;

            if (map[i][j] == 2) {
                v[c] = { i,j };
                if (j == N - 1) {
                    search(i + 1, 0, c + 1);
                }
                else {
                    search(i, j + 1, c + 1);
                }
            }
        }
    }
}

int main()
{
    // 코드를 작성해주세요

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)cnt++;
        }
    }

    search(0,0,0);

    if (cnt == 0)ans = -1;
    if (ans == 2500)ans = -2;
    cout << ans + 1 << "\n";
    
    return 0;
}