#include<iostream>

using namespace std;

typedef long long int ll;

ll a, b, c;
int result = 0;
ll pow(ll x, ll m);

int main() {

	cin >> a >> b >> c;

	cout << pow(a, b) % c;

	return 0;
}

//짝수와 홀수로 나눠서 분할 정복
ll pow(ll x, ll m) {
	if (m == 0)
		return 1;
	else if (m == 1)
		return x;
	if (m % 2 > 0)
		return pow(x, m - 1) * x;
	ll half = pow(x, m / 2);
	half %= c;
	return (half * half) % c;
}