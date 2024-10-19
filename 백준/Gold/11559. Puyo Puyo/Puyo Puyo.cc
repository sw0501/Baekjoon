#include<bits/stdc++.h>

using namespace std;

string field[12];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 12; i++) {
        cin >> field[i];
    }

    int flag = 1;
    int cnt = 0;
    while (flag) {
        //연쇄 발생 여부
        flag = 0;
        int visit[12][6] = { 0, };
        int c[100] = { 0, };
        int num = 0;

        //연쇄될 블록 확인
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                //처음 보는 블럭인 경우
                if (field[i][j] != '.' && !visit[i][j]) {
                    queue<pair<int, int>>q;
                    q.push({ i,j });
                    num++;
                    c[num] = 1;
                    visit[i][j] = num;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;

                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int tx = x + dx[k];
                            int ty = y + dy[k];

                            if (tx >= 0 && tx < 12 && ty >= 0 && ty < 6) {
                                if (field[tx][ty] == field[x][y] && !visit[tx][ty]) {
                                    visit[tx][ty] = num;
                                    q.push({ tx,ty });
                                    c[num]++;
                                }
                            }
                        }
                    }
                }
            }
        }


        //블럭 파괴
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (visit[i][j] && c[visit[i][j]] >= 4) {
                    field[i][j] = '.';
                    flag = 1;
                }
            }
        }

        //블럭 이동
        for (int j = 0; j < 6; j++) {
            for (int i = 11; i >= 0; i--) {
                //빈칸인 경우
                if (field[i][j] == '.') {
                    for (int k = i - 1; k >= 0; k--) {
                        if (field[k][j] != '.') {
                            field[i][j] = field[k][j];
                            field[k][j] = '.';
                            break;
                        }
                    }
                }
            }
        }

        if (flag)cnt++;
    }

    cout << cnt << "\n";
   
    return 0;
}