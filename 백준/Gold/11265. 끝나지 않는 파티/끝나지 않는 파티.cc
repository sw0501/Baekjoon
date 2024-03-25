#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int N, M;

int arr[501][501];

int main() {
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)continue;
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		if (arr[A][B] <= C) {
			cout << "Enjoy other party" << "\n";
		}
		else {
			cout << "Stay here" << "\n";
		}
	}

	return 0;
}