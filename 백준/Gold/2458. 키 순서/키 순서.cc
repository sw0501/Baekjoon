#include<iostream>
#include<cmath>

using namespace std;

int INF = 1000000000;
int t[501][501] = { 0, };
int s[501][501] = { 0, };

int main() {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j)continue;
            t[i][j] = INF;
            s[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {

        int a, b;
        cin >> a >> b;

        t[a][b] = 1;
        s[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
                s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        int flag = 1;
        for (int j = 1; j <= N; j++) {
            if (t[i][j] == INF && s[i][j] == INF)flag = 0;
        }
        ans += flag;
    }

    cout << ans << "\n";

    return 0;
}