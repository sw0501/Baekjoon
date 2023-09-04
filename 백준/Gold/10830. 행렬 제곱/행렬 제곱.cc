#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

long long n;

matrix operator *(const matrix &A, const matrix&B) {
	int size = A.size();
	matrix res(size, vector<long long>(size));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				res[i][j] += A[i][k] * B[k][j];
			}
			res[i][j] %= 1000;
		}
	}

	return res;
}

matrix power(matrix &A, long long b) {

	int size = A.size();
	matrix res(size, vector<long long>(size));

	for (int i = 0; i < size; i++) {
		res[i][i] = 1;
	}

	while (b > 0) {
		if (b % 2 == 1) {
			b -= 1;
			res = res * A;
		}
		else {
			A = A * A;
			b /= 2;
		}
	}

	return res;
}

int main() {

	long long b;

	cin >> n >> b;


	matrix A;

	for (int i = 0; i < n; i++) {
		vector<long long> temp;
		A.push_back(temp);
		for (int j = 0; j < n; j++) {
			long long num;
			cin >> num;
			A[i].push_back(num);
		}
	}

	matrix ans = power(A, b);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}