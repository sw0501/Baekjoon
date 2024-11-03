#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int N, L;
    cin >> N >> L;

    int s = -1;
    int cnt = 0;

    //L개의 수열의 합 수식
    //N = x + (x + 1) + . . . + (x + (L-1))
    //N = L * x + (1 + L) * L / 2

    //배열 길이만큼 탐색
    for (int i = L; i <= 100; i++) {

        //수열의 길이의 합
        //1 + 2 + ... + L
        int t = i * (i - 1) / 2;

        //시작 수가 정수인 경우
        //길이가 L 이상인 경우
        if ((N - t) % i == 0 && (N - t) / i >= 0) {
            s = (N - t) / i;
            cnt = i;
            break;
        }
    }

    if (s < 0) {
        cout << -1 << "\n";
    }
    else {
        for (int i = 0; i < cnt; i++) {
            cout << s + i << " ";
        }
    }

    return 0;
}
