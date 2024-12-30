#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> people[501];
int visit[501] = { 0, };

int main()
{
    // 코드를 작성해주세요

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        people[a].push_back(b);
        people[b].push_back(a);
    }

    queue<pair<int, int>> q;
    q.push({ 1,0 });
    visit[1] = 1;

    int cnt = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int d = q.front().second;
        q.pop();

        if (d == 2)continue;

        for (int i = 0; i < people[x].size(); i++) {
            if (!visit[people[x][i]]) {
                cnt++;
                visit[people[x][i]] = 1;
                q.push({ people[x][i],d + 1 });

            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
