#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    pair<int, int> direction[4] = { {-1,0},{0,1},{1,0},{0,-1} };

    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    
    int N, M;
    int room[51][51] = { 0, };
    cin >> N >> M;
    
    int x, y, d;
    cin >> x >> y >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    int cnt = 0;

    while (1) {
        //현재 칸이 청소되지 않은 경우
        if (room[x][y] == 0) {
            cnt++;
            room[x][y] = 2;
        }
        else {
            int flag = 0;
            
            for (int k = 0; k < 4; k++) {
                int tx = x + dx[k];
                int ty = y + dy[k];

                //유효 범위인 경우
                if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
                    if (room[tx][ty] == 0) {
                        flag = 1;
                        break;
                    }
                }
            }

            //청소되지 않은 빈칸이 존재하는 경우
            if (flag) {
                for (int k = 0; k < 4; k++) {
                    //반시계방향으로 회전
                    d = (d - 1 < 0 ? 3 : d - 1);

                    //전방 이동가능한지 확인
                    int tx = x + direction[d].first;
                    int ty = y + direction[d].second;

                    //전진 가능한 경우
                    if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
                        if (room[tx][ty] == 0) {
                            x = tx;
                            y = ty;
                            break;
                        }
                    }
                }
            }

            //모두 청소된 경우
            else {
                int tx = x - direction[d].first;
                int ty = y - direction[d].second;

                //후진 가능한 경우
                if (tx >= 0 && tx < N && ty >= 0 && ty < M && room[tx][ty] != 1) {
                    x = tx;
                    y = ty;
                }
                else {
                    break;
                }
            }
        }
    }

    cout << cnt << "\n";

    return 0;

}