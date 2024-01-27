#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int A[10001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//1 A[i] 라면 하나 3 -> 
	//2 A[i] A[i+1] 라면 한개 5 -> 
	//3 A[i] A[i+1] A[i+2] 라면 한 개 7 -> 

		int N;
		long long int ans = 0;
		long long int tempPrice[3] = { 0, };
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		long long int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (i < N - 2) {
				if (A[i + 1] > A[i + 2]) {
					cnt = min(A[i], A[i + 1] - A[i + 2]);
					ans += cnt * 5;
					A[i] -= cnt;
					A[i + 1] -= cnt;
				}
				cnt = min(A[i], min(A[i + 1], A[i + 2]));
				ans += cnt * 7;
				A[i] -= cnt;
				A[i + 1] -= cnt;
				A[i + 2] -= cnt;
			}
			if (i < N - 1) {
				cnt = min(A[i], A[i + 1]);
				ans += cnt * 5;
				A[i] -= cnt;
				A[i + 1] -= cnt;
			}
			ans += A[i] * 3;
			A[i] = 0;
		}

		cout << ans << "\n";
	return 0;
}