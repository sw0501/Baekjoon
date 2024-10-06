#include <bits/stdc++.h>

using namespace std;

char arr[5][5] = { 0, };
int maxDP[5][5] = { 0, };
int minDP[5][5] = { 0, };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			maxDP[i][j] = -10000000;
			minDP[i][j] = 100000000;
		}
	}

	maxDP[0][0] = (int)(arr[0][0] - '0');
	minDP[0][0] = (int)(arr[0][0] - '0');
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] >= '0' && arr[i][j] <= '9') {
				if (j + 2 < N) {
					switch (arr[i][j + 1]) {
					case '+':
						maxDP[i][j + 2] = max(maxDP[i][j + 2], maxDP[i][j] + (int)(arr[i][j + 2] - '0'));
						minDP[i][j + 2] = min(minDP[i][j + 2], minDP[i][j] + (int)(arr[i][j + 2] - '0'));
						break;
					case '-':
						maxDP[i][j + 2] = max(maxDP[i][j + 2], maxDP[i][j] - (int)(arr[i][j + 2] - '0'));
						minDP[i][j + 2] = min(minDP[i][j + 2], minDP[i][j] - (int)(arr[i][j + 2] - '0'));
						break;
					case '*':
						maxDP[i][j + 2] = max(maxDP[i][j + 2], maxDP[i][j] * (int)(arr[i][j + 2] - '0'));
						minDP[i][j + 2] = min(minDP[i][j + 2], minDP[i][j] * (int)(arr[i][j + 2] - '0'));
						break;
					}

				}
				if (i + 2 < N) {
					switch (arr[i + 1][j]) {
					case '+':
						maxDP[i + 2][j] = max(maxDP[i + 2][j], maxDP[i][j] + (int)(arr[i + 2][j] - '0'));
						minDP[i + 2][j] = min(minDP[i + 2][j], minDP[i][j] + (int)(arr[i + 2][j] - '0'));
						break;
					case '-':
						maxDP[i + 2][j] = max(maxDP[i + 2][j], maxDP[i][j] - (int)(arr[i + 2][j] - '0'));
						minDP[i + 2][j] = min(minDP[i + 2][j], minDP[i][j] - (int)(arr[i + 2][j] - '0'));
						break;
					case '*':
						maxDP[i + 2][j] = max(maxDP[i + 2][j], maxDP[i][j] * (int)(arr[i + 2][j] - '0'));
						minDP[i + 2][j] = min(minDP[i + 2][j], minDP[i][j] * (int)(arr[i + 2][j] - '0'));
						break;
					}
				}

				if (i + 1 < N && j + 1 < N) {
					switch (arr[i + 1][j]) {
					case '+':
						maxDP[i + 1][j + 1] = max(maxDP[i + 1][j + 1], maxDP[i][j] + (int)(arr[i + 1][j + 1] - '0'));
						minDP[i + 1][j + 1] = min(minDP[i + 1][j + 1], minDP[i][j] + (int)(arr[i + 1][j + 1] - '0'));
						break;
					case '-':
						maxDP[i + 1][j + 1] = max(maxDP[i + 1][j + 1], maxDP[i][j] - (int)(arr[i + 1][j + 1] - '0'));
						minDP[i + 1][j + 1] = min(minDP[i + 1][j + 1], minDP[i][j] - (int)(arr[i + 1][j + 1] - '0'));
						break;
					case '*':
						maxDP[i + 1][j + 1] = max(maxDP[i + 1][j + 1], maxDP[i][j] * (int)(arr[i + 1][j + 1] - '0'));
						minDP[i + 1][j + 1] = min(minDP[i + 1][j + 1], minDP[i][j] * (int)(arr[i + 1][j + 1] - '0'));
						break;
					}
					switch (arr[i][j + 1]) {
					case '+':
						maxDP[i + 1][j + 1] = max(maxDP[i + 1][j + 1], maxDP[i][j] + (int)(arr[i + 1][j + 1] - '0'));
						minDP[i + 1][j + 1] = min(minDP[i + 1][j + 1], minDP[i][j] + (int)(arr[i + 1][j + 1] - '0'));
						break;
					case '-':
						maxDP[i + 1][j + 1] = max(maxDP[i + 1][j + 1], maxDP[i][j] - (int)(arr[i + 1][j + 1] - '0'));
						minDP[i + 1][j + 1] = min(minDP[i + 1][j + 1], minDP[i][j] - (int)(arr[i + 1][j + 1] - '0'));
						break;
					case '*':
						maxDP[i + 1][j + 1] = max(maxDP[i + 1][j + 1], maxDP[i][j] * (int)(arr[i + 1][j + 1] - '0'));
						minDP[i + 1][j + 1] = min(minDP[i + 1][j + 1], minDP[i][j] * (int)(arr[i + 1][j + 1] - '0'));
						break;
					}
				}

			}
		}
	}
	
	cout << maxDP[N - 1][N - 1] << " "<< minDP[N - 1][N - 1] << "\n";
 
	return 0;
}