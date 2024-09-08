#include<bits/stdc++.h>

using namespace std;

int prefixSum[250001] = { 0, };

int main() {

	int N, X;
	cin >> N >> X;

	for (int i = 1; i <= N; i++) {
		cin >> prefixSum[i];
		prefixSum[i] += prefixSum[i - 1];
	}

	int M = -1;
	int cnt = 0;
	for (int i = X; i <= N; i++) {
		int num = prefixSum[i] - prefixSum[i - X];
		if (M < num) {
			M = num;
			cnt = 1;
		}
		else if (M == num) {
			cnt++;
		}
	}

	if (M == 0) {
		cout << "SAD" << "\n";
	}
	else {
		cout << M << "\n" << cnt << "\n";
	}

	return 0;
}