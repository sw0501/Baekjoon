#include<iostream>
#include<queue>
#include<utility>
#include<vector>

using namespace std;

typedef long long ll;
ll MOD = 1000000007;

ll f(ll a, ll b) {
    if (b == 1)return a;
    if (b % 2 == 1)return a * f(a, b - 1) % MOD;
    ll c = f(a, b / 2);
    return c * c % MOD;
}

ll gcd(ll a, ll b) {
    if (a < b) {
        ll tmp = a;
        a = b;
        b = tmp;
    }

    while (b != 0) {
        ll c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int m;
    cin >> m;

    int ans = 0;
    for (int i = 0; i < m; i++) {

        ll a, b;
        cin >> b >> a;
        ll g = gcd(a, b);

        b /= g;
        a /= g;

        ans += a * f(b, MOD - 2) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}