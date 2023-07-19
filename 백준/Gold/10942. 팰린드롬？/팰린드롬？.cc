#include<iostream>

using namespace std;

int arr[2001];
bool DP[2001][2001] = { false, };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	//DP[S][E] = DP[S+1][E-1] + 2;

	for (int i = 1; i <= N; i++) {
		DP[i][i] = true;
		if (i < N && arr[i] == arr[i + 1]) {
			DP[i][i + 1] = true;
		}
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = i + 2; j <= N; j++) {
			if (arr[i] == arr[j] && DP[i + 1][j - 1] == true) {
				DP[i][j] = true;
			}
		}
	}
	
	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;

		if (DP[S][E])cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	

	return 0;
}