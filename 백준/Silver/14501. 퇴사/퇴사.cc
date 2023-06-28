#include<iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	int T[15];
	int P[15];
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}


	int DP[16] = { 0, };

	for (int i = N-1; i>=0 ; i--) {
		int deadline = i + T[i];
		if (deadline > N) {
			DP[i] = DP[i + 1];
		}
		else {
			DP[i] = (DP[deadline] + P[i] > DP[i + 1] ? DP[deadline] + P[i] : DP[i + 1]);
		}
	}

	cout << DP[0] << "\n";

	return 0;
}