#include<bits/stdc++.h>
using namespace std;

using ll = long long int;

int N, M;
vector<ll>K;
vector<priority_queue<ll, vector<ll>, greater<ll>>> pos(10);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // 기울기 저장
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        K.push_back(num);
    }

    // 좌표 저장
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        for (int j = 0; j < M; j++) {
            pos[j].push(y - K[j] * x);
        }
    }

    ll ans = 0;

    // 이동 가능한 좌표 탐색
    for (int i = 0; i < M; i++) {

        ll cnt = 1;

        // 마지막 원소까지 포함해서 처리
        while (pos[i].size() > 0) {
            ll t = pos[i].top();
            pos[i].pop();

            if (!pos[i].empty() && t == pos[i].top()) {
                // 같은 직선 상에 위치해 있다면
                cnt++;
            }
            else {
                // 페어 가능 개수 추가
                ans += (cnt * (cnt - 1));
                cnt = 1;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}