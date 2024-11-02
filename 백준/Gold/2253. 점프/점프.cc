#include <bits/stdc++.h>

using namespace std;

//현재 돌 / 이전 점프 갯수
int DP[10001][501] = { 0, };
int ck[10001] = { 0, };

int N, M;

int INF = 100000000;

int jump(int p, int v) {
    if (p == N)return 0;

    if (p > N || ck[p])return INF;

    if (DP[p][v] != -1)return DP[p][v];

    DP[p][v] = INF;

    if (!ck[p + v]) {
        DP[p][v] = min(DP[p][v], jump(p + v , v) + 1);
    }
    if (!ck[p + v + 1]) {
        DP[p][v] = min(DP[p][v], jump(p + v + 1, v + 1) + 1);
    }
    if (!ck[p + v - 1] && v - 1  >= 0) {
        DP[p][v] = min(DP[p][v], jump(p + v - 1, v - 1) + 1);
    }

    return DP[p][v];
}

int main()
{
    // 코드를 작성해주세요
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        ck[num] = 1;
    }

    memset(DP, -1, sizeof(DP));

    int answer = jump(1, 0);

    if (answer == INF) {
        cout << -1 << "\n";
    }
    else cout << answer << "\n";

    return 0;
}
