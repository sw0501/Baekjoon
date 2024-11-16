#include <iostream>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

int N, L, R;

int arr[51][51] = { 0, };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int c = 0;

    while (1) {
        int flag = 1;

        queue<pair<int, int>>q;
        unordered_map<int, int> m;

        int visit[51][51] = { 0, };
        int num = 1;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visit[i][j]) {
                    int total = arr[i][j];
                    int cnt = 1;

                    q.push({ i,j });
                    visit[i][j] = num;

                    
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int tx = x + dx[k];
                            int ty = y + dy[k];

                            if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
                                if (visit[tx][ty])
                                    continue;
                                if (!(L <= abs(arr[x][y] - arr[tx][ty])&& abs(arr[x][y] - arr[tx][ty]) <= R))
                                    continue;
                                visit[tx][ty] = num;
                                q.push({ tx,ty });
                                total += arr[tx][ty];
                                cnt++;

                                flag = 0;

                            }
                        }
                    }

                    m.insert({ num,total / cnt });
                    num++;
                }
            }
        }

        if (flag)break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = m[visit[i][j]];
            }
        }
        c++;
    }

    cout << c << "\n";

    return 0;
}