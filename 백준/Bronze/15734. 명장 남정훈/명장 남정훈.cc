#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    // 코드를 작성해주세요
    int L, R, A;
    cin >> L >> R >> A;

    int t = L + R + A;

    if (L < R) {
        int d = min(R - L, A);
        L += d;
        A -= d;
    }
    else {
        int d = min(L - R, A);
        R += d;
        A -= d;
    }

    if (R == L) {
        cout << t - (A % 2) << "\n";
    }
    else {
        cout << t - abs(R - L);
    }



    return 0;
}
