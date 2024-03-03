#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;


long long int ans = 1;
long long int MAX = 1000000000;
long long int DP[1000001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n;


	cin >> n;

	DP[1] = 0;
	DP[2] = 1;

	//교란 순열 DP로 계산
	for (int i = 3; i <= n; i++) {
		DP[i] = ((i - 1) * (DP[i - 1] + DP[i - 2])) % MAX;
	}

	cout << (DP[n]) % MAX << "\n";


	return 0;
}