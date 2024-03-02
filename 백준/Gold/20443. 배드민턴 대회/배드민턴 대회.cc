#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;


long long int ans = 1;
long long int MAX = 1000000007;
long long int DP[101] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n;
	

	cin >> n;

	if (n % 4 != 0) {
		for (int i = 1; i <= n % 4; i++) {
			ans *= (n - i + 1);
			ans /= i;
		}
	}

	DP[1] = 0;
	DP[2] = 1;

	//교란 순열 DP로 계산
	for (int i = 3; i <= n; i++) {
		DP[i] = ((i - 1) * (DP[i - 1] + DP[i - 2])) % MAX;
	}

	cout << (ans * DP[n - n % 4]) % MAX << "\n";
	

	return 0;
}