#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>>node[100001];
int visit[100001] = { 0, };

int main()
{
    // 코드를 작성해주세요

    int N, M, R;
    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        node[a].push(b);
        node[b].push(a);
    }

    queue<int>bfs;
    visit[R] = 1;
    bfs.push(R);

    int t = 2;
    while (!bfs.empty()) {
        int n = bfs.front();
        bfs.pop();

        while (!node[n].empty()) {
            if (!visit[node[n].top()]) {
                visit[node[n].top()] = t++;
                bfs.push(node[n].top());
            }
            node[n].pop();
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << visit[i] << "\n";
    }

    return 0;
}
