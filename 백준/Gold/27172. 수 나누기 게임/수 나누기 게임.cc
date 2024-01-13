#include<iostream>
#include<algorithm>

using namespace std;

struct player {
    int idx;
    int num;
    int score;
};

bool compare_score(player& a, player& b) {
    return a.num < b.num;
}

bool compare_idx(player& a, player& b) {
    return a.idx < b.idx;
}

int N;
int decimal[1000001] = { 0, };
int p[100001] = { 0, };
int cards[1000001] = { 0, };
int score[1000001] = { 0, };

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //점수 입력
    cin >> N;

    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        cards[num] = 1;
        p[i] = num;
    }

    //모든 카드마다 에라스토테네스 체 이용하여 탐색
    for (int i = 0; i < N; i++) {
        for (int j = p[i] * 2; j <= 1000000; j += p[i]) {
            //해당 카드를 가진 플레이어가 존재하는 경우
            if (cards[j] == 1) {
                score[p[i]]++;
                score[j]--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << score[p[i]] << " ";
    }

    return 0;
}