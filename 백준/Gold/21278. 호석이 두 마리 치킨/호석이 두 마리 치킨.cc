#include<bits/stdc++.h>

using namespace std;

int B[101][101];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	const int INF = INT_MAX;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			B[i][j] = 10000000;
			if (i == j)B[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		B[a][b] = 1;
		B[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (i == j)continue;
				B[i][j] = min(B[i][j],B[i][k] + B[k][j]);
			}
		}
	}

	int a = 101, b = 101;
	int sum = INT_MAX;

	//2개 고르기
	for (int i = 1; i <= N; i++){
		for (int j = i+1; j <= N; j++) {
			if (i == j)continue;
			//검사
			int tempSum = 0;
			for (int k = 1; k <= N; k++) {
				if (!(k == i || k == j)) {
					tempSum += min(B[k][i], B[k][j]);
				}
			}
			
			if (tempSum < sum) {
				a = i;
				b = j;
				sum = tempSum;
			}
			else if (tempSum == sum) {
				if (a > i) {
					a = i;
				}
				if (b > j) {
					b = j;
				}
			}
		}
	}

	cout << a << " " << b << " " << sum*2;

	return 0;
}