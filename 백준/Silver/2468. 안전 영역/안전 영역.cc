#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[101][101] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
    // 코드를 작성해주세요
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    int answer = 0;
    for (int h = 0; h <= 100; h++) {
        int visit[101][101] = { 0, };
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] > h && !visit[i][j]) {
                    visit[i][j] = 1;
                    cnt++;
                    queue<pair<int, int>>q;
                    q.push({ i,j });

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int tx = x + dx[k];
                            int ty = y + dy[k];

                            if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
                                if (map[tx][ty] > h && !visit[tx][ty]) {
                                    visit[tx][ty] = 1;
                                    q.push({ tx,ty });
                                }
                            }
                        }
                    }
                }
            }
        }
        answer = (answer > cnt ? answer : cnt);
    }

    cout << answer << "\n";

    return 0;
}