#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

pair<int, int> p[200001];

struct compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    priority_queue<int,vector<int>,compare>pq;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p, p + N);

    pq.push(p[0].second);
    for (int i = 1; i < N; i++) {
        pq.push(p[i].second);

        //수업 진행이 가능한 경우
        if (p[i].first >= pq.top()) {
            pq.pop();
        }
    }

    cout << pq.size();

    return 0;
}