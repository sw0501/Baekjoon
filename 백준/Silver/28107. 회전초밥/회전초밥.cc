#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;


int cnt[100001] = { 0, };
queue<int>q[200001];

int main()
{
    // 코드를 작성해주세요

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        for (int k = 0; k < K; k++) {
            int num;
            cin >> num;
            q[num].push(i);
        }
    }

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        if (!q[num].empty()) {
            cnt[q[num].front()]++;
            q[num].pop();
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << cnt[i] << " ";
    }
    return 0;
}
