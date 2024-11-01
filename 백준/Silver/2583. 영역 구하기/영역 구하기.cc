#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int arr[101][101] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
    // 코드를 작성해주세요
    int M, N, K;
    cin >> N >> M >> K;

    for (int k = 0; k < K; k++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int i = b; i < d; i++) {
            for (int j = a; j < c; j++) {
                arr[i][j] = 1;
            }
        }

    }

    queue<pair<int, int>> q;

    vector<int> answer;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                q.push({ i,j });
                arr[i][j] = 1;
                int cnt = 0;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    cnt++;

                    for (int k = 0; k < 4; k++) {
                        int tx = x + dx[k];
                        int ty = y + dy[k];

                        if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
                            if (arr[tx][ty] == 0) {
                                q.push({ tx,ty });
                                arr[tx][ty] = 1;
                            }
                        }
                    }
                }
                answer.push_back(cnt);
            }
        }
    }

    sort(answer.begin(),answer.end());
    cout << answer.size() << "\n";

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    return 0;
}