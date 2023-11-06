#include<iostream>
#include<queue>
#include<utility>
#include<vector>

using namespace std;

int arr[101][101] = { 0, };
int ck[101][101] = { 0, };
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS() {
    queue<pair<int,int>>q;

    q.push({ 0,0 });
    ck[0][0] = 1;
    arr[0][0] = -1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();

        for (int k = 0; k < 4; k++) {
            int tx = x + dx[k];
            int ty = y + dy[k];

            if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
                //접촉하지 않은 외부 공기인 경우 표시
                if (arr[tx][ty] == 0 && ck[tx][ty] !=1) {
                    ck[tx][ty] = 1;
                    arr[tx][ty] = -1;
                    q.push({ tx,ty });
                }
            }
        }
    }
}

int main() {

    int cheese = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)cheese++;
        }
    }

    //외부 공기 탐색
    BFS();

    queue<pair<int,int>>q;

    int t = 0;
    while (cheese) {

        //녹는 치즈 탐색
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                //치즈인 경우
                if (arr[i][j] == 1) {
                    int flag = 0;
                    for (int k = 0; k < 4; k++) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
                            if (arr[tx][ty] == -1)flag++;
                            if (flag >= 2) {
                                break;
                            }
                        }
                    }
                    if (flag >= 2) {
                        cheese--;
                        q.push({ i,j });
                    }
                }
            }
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            arr[x][y] = -1;
            ck[x][y] = 1;

            q.pop();

            for (int k = 0; k < 4; k++) {
                int tx = x + dx[k];
                int ty = y + dy[k];

                if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
                    //접촉하지 않은 외부 공기인 경우 표시
                    if (arr[tx][ty] == 0 && ck[tx][ty] != 1) {
                        ck[tx][ty] = 1;
                        arr[tx][ty] = -1;
                        q.push({ tx,ty });
                    }
                }
            }
        }
        t++;
    }

    cout << t << "\n";
    return 0;
}