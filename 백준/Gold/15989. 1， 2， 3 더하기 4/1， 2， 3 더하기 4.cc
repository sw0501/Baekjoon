#include<bits/stdc++.h>
using namespace std;


int DP[10001][4] = {0,};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        DP[1][1] = 1;   // 1

        DP[2][1] = 1;   // 1 1
        DP[2][2] = 1;   // 2

        DP[3][1] = 1;   //1 1 1
        DP[3][2] = 1;   //1 2
        DP[3][3] = 1;   //3

        int N;
        cin >> N;

        for (int n = 4; n <= N; n++) {
            DP[n][1] = DP[n - 1][1];
            DP[n][2] = DP[n - 2][1] + DP[n - 2][2];
            DP[n][3] = DP[n - 3][1] + DP[n - 3][2] + DP[n - 3][3];
        }
        
        cout << DP[N][1] + DP[N][2] + DP[N][3] << "\n";
    }
    
    //1 2 
    return 0;
}