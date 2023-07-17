#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

    int N;
    cin >> N;

    int arr[17][17] = { 0, };
    int DP[3][17][17] = { 0, };   //0; 가로 , 1: 세로, 2: 대각선

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    int rotate = 1;    // 1 가로, 0 대각선, -1 세로

    DP[0][1][2] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            //if (i == 1 && j == 1)continue;  //첫번째 칸은 피하기

            //가로 옮기기
            //다음에 밀 칸에 벽이 있는 경우 제외
            if (j < N && !arr[i][j + 1] && DP[0][i][j] != 0) {
                //가로로 그대로 밀기
                //DP[0][i][j + 1] = max(DP[0][i][j + 1], DP[0][i][j]);
                DP[0][i][j + 1] += DP[0][i][j];

                //대각선으로 밀기 (대각선이 지나가는 방향에 벽이 있으면 안됨
                if (i < N && j < N && !arr[i + 1][j] && !arr[i + 1][j + 1]) {
                    //DP[2][i + 1][j + 1] = max(DP[2][i + 1][j + 1], DP[0][i][j]);
                    DP[2][i + 1][j + 1] += DP[0][i][j];
                }
            }
            


            //세로 옮기기 
            if (i < N && !arr[i + 1][j] && DP[1][i][j] != 0) {
                //세로로 그대로 밀기
                //DP[1][i + 1][j] = max(DP[1][i + 1][j], DP[1][i][j]);
                DP[1][i + 1][j] += DP[1][i][j];

                //대각선으로 밀기
                if (i < N && j < N && !arr[i][j + 1] && !arr[i + 1][j + 1]) {
                    //DP[2][i + 1][j + 1] = max(DP[2][i + 1][j + 1], DP[1][i][j]);
                    DP[2][i + 1][j + 1] += DP[1][i][j];
                }
            }
            

            //대각선으로 옮기기
            if (DP[2][i][j] != 0) {
                //가로로 밀기
                if (j < N && !arr[i][j + 1]) {
                    //DP[0][i][j + 1] = max(DP[0][i][j + 1], DP[2][i][j]);
                    DP[0][i][j + 1] += DP[2][i][j];
                }
                
                //세로로 밀기
                if (i < N && !arr[i + 1][j]) {
                    //DP[0][i + 1][j] = max(DP[0][i + 1][j], DP[2][i][j]);
                    DP[1][i + 1][j] += DP[2][i][j];
                }

                //대각선으로 그대로 옮기기
                if (i < N && j < N && !arr[i][j + 1] && !arr[i + 1][j] && !arr[i + 1][j + 1]) {
                    //DP[2][i + 1][j + 1] = max(DP[2][i + 1][j + 1], DP[2][i][j]);
                    DP[2][i + 1][j + 1] += DP[2][i][j];
                }
            }

        }
    }

    /*
    cout << "\n";

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << DP[0][i][j] << DP[1][i][j] << DP[2][i][j] << " ";
        }
        cout << "\n";
    }
    */

    cout << DP[0][N][N] + DP[1][N][N] + DP[2][N][N];

    return 0;
}