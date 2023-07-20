#include<iostream>

using namespace std;

long long DP[1000001] = { 0, };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	int T;
	cin >> T;

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	
	for (int i = 4; i <= 1000000; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3])% 1000000009;
	}

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		
		cout << DP[N] << "\n";
	}

	return 0;
}