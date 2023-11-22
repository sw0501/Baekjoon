#include<iostream>
#include<cmath>

using namespace std;

int INF = 250000000;
int graph[401][401] = { 0, };

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
            int a, b;
            cin >> a >> b;
            graph[a][b] = -1;
            graph[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j)continue;

                // 1 1 이거나 -1 -1 인 경우에만 대소 비교
                if (graph[i][k] == graph[k][j] && graph[i][k] != 0) {
                    graph[i][j] = graph[i][k];
                }
            }
        }
    }

    int s;
    cin >> s;

    for (int i = 0; i < s; i++) {
        int a, b;
        cin >> a >> b;
        if (graph[a][b] == INF)graph[a][b] = 0;
        cout << graph[a][b] << "\n";
    }

    return 0;
}