#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>


using namespace std;

int MAX = 123456789;
int graph[201][201] = { 0, };
int node[201][201] = { 0, };
int dest[201][201] = { 0, };

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
        dest[a][b] = b;
        dest[b][a] = a;
        node[a][b] = 1;
        node[b][a] = 1;
    }

    //i->k->j
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)continue;
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    //직접 연결된 정점인 경우
                    dest[i][j] = dest[i][k];
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dest[i][j] == 0) {
                cout << "- ";
            }
            else {
                cout << dest[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}