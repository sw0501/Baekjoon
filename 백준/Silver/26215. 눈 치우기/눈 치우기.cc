#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // 코드를 작성해주세요
    int N;
    cin >> N;

    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        pq.push(n);
    }

    int cnt = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        cnt += min(a, b);

        int last = max(a, b) - min(a, b);

        if (last)pq.push(last);
    }

    if (!pq.empty()) {
        cnt += pq.top();
        pq.pop();
    }

    if (cnt > 1440)cnt = -1;
    cout << cnt << "\n";
    return 0;
}
