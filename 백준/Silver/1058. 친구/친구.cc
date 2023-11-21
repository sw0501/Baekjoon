#include<iostream>
#include<cmath>

using namespace std;

int INF = 50000;
int graph[51][51] = { 0, };
int f[51][51] = { 0, };

int main() {

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)continue;
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == 'Y')graph[i][j] = 1;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j)continue;
                if (graph[i][j] == 1 || graph[i][k] == 1 && graph[k][j] == 1) {
                    f[i][j] = 1;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (f[i][j] == 1)temp++;
        }
        cnt = max(cnt, temp);
    }

    cout << cnt << "\n";

    return 0;
}