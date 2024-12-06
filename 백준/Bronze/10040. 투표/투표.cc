#include <iostream>

using namespace std;

int main()
{
    // 코드를 작성해주세요

    int N, M;
    int list[1001] = { 0, };
    int cnt[1001] = { 0, };

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < M; i++) {
        int score;
        cin >> score;

        int M = -1;
        int idx = 0;

        for (int j = 0; j < N; j++) {
            if (list[j] <= score) {
                idx = j;
                break;
            }
        }

        cnt[idx]++;
    }

    int idx = 0;
    for (int i = 0; i < N; i++) {
        idx = (cnt[idx] > cnt[i] ? idx : i);
    }
    cout << idx + 1 << "\n";

    return 0;
}
