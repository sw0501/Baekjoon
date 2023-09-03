#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

matrix multiply(matrix&A, matrix&B) {
	matrix C = { {0,0},{0,0} };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % 1000000007;
			}
		}
	}
	return C;
}


int main() {

	long long n;
	cin >> n;

	matrix ans = { {1,0},{0,1} };
	matrix A = { {1,1},{1,0} };

	//F[n] = F[n-1] + F[n-2]
	//F[n-1] = F[n-2] + F[n-3];
	//F[n-2] = F[n-3] + F[n-4]

	while (n > 0) {
		if (n % 2 == 1) {
			ans = multiply(ans, A);
		}
		A = multiply(A, A);
		n /= 2;
	}
	cout << ans[0][1] << "\n";

	


	return 0;
}