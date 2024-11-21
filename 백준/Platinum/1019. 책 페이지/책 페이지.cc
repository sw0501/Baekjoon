#include <bits/stdc++.h>
using namespace std;

//숫자 카운트
int cnt[10] = { 0, };

int main() {

    //입력 받는 수
    int N;


    //추가로 계산해야하는 수
    int add = 0;
    cin >> N;

    int i = 1;
    while (N > 0) {
        int num = N % 10;
        N /= 10;
        cnt[0] -= i;

        //현재 수 보다 작은 수 (N+1) * i 번 추가
        for (int j = 0; j < num; j++) {
            cnt[j] += (N + 1) * i;
        }

        //현재 수
        //N * i + 1 + add번 추가
        cnt[num] += N * i + 1 + add;

        //현재 수 보다 큰 수
        //N * i 번 추가
        for (int j = num + 1; j <= 9; j++) {
            cnt[j] += N * i;
        }

        add += num * i;
        i *= 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << " ";
    }
}