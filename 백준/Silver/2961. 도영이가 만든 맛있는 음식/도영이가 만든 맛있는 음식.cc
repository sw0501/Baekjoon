/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <climits>
using namespace std;

struct food {
    int s;
    int b;
};

int N;
food f[10];
long long int ans = INT_MAX;
int ck[10] = { 0, };

void BruteForce(int idx, long long int s, long long int b) {
    for (int i = idx; i < N; i++) {
        if (ck[i] == 1)continue;
        ck[i] = 1;
        long long int diff = (s * f[i].s) - (b + f[i].b);
        diff = (diff > 0 ? diff : -diff);
        ans = (ans > diff ? diff : ans);
        BruteForce(0, s * f[i].s, b + f[i].b);
        ck[i] = 0;
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> f[i].s;
        cin >> f[i].b;
    }

    BruteForce(0, 1, 0);

    cout << ans << "\n";

    return 0;
}
