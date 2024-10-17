#include<bits/stdc++.h>

using namespace std;

//정보, 전산
int arr[8][8];

//각 시간별로 도착하는 경우의 수
int DP[100001][8] = {0,};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    arr[0][1] = 1;
    arr[0][3] = 1;
    arr[1][0] = 1;
    arr[1][2] = 1;
    arr[1][3] = 1;
    arr[2][1] = 1;
    arr[2][3] = 1;
    arr[2][4] = 1;
    arr[2][5] = 1;
    arr[3][0] = 1;
    arr[3][1] = 1;
    arr[3][2] = 1;
    arr[3][5] = 1;
    arr[4][2] = 1;
    arr[4][5] = 1;
    arr[4][6] = 1;
    arr[5][2] = 1;
    arr[5][3] = 1;
    arr[5][4] = 1;
    arr[5][7] = 1;
    arr[6][4] = 1;
    arr[6][7] = 1;
    arr[7][5] = 1;
    arr[7][6] = 1;

    int D;
    cin >> D;

    DP[0][0] = 1;
    for (int i = 1; i <= D; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                DP[i][j] += DP[i - 1][k] * arr[j][k];
                DP[i][j] %= 1000000007;
            }
        }
    }

    cout << DP[D][0] << "\n";

    return 0;
}