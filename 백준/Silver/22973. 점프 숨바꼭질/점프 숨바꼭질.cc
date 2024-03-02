#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int K;
    cin >> K;

    K = (K > 0 ? K : -K);

    if (K == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    if (K % 2 == 0) {
        cout << -1 << "\n";
        return 0;
    }

    long long int cnt = 0;
    while (K > 0) {
        K /= 2;
        cnt++;
    }

    cout << cnt << "\n";

    return 0;
}