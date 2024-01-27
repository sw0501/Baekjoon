#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

long long int A[1000001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int N;
	long long int B=3, C=2;
	long long int ans = 0;
	cin >> N >> B >> C;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	long long int cnt = 0;
	for (int i = 0; i < N; i++) {
		//B <= C인 경우는 개별로 사는 것이 최적의 해
		if (B > C) {
			if (i < N - 2) {
				//단가 계산 필요
				if (A[i + 1] > A[i + 2]) {
					cnt = min(A[i], A[i + 1] - A[i + 2]);
					ans += cnt * (B + C);
					A[i] -= cnt;
					A[i + 1] -= cnt;
				}
				cnt = min(A[i], min(A[i + 1], A[i + 2]));
				ans += cnt * (B + 2 * C);
				A[i] -= cnt;
				A[i + 1] -= cnt;
				A[i + 2] -= cnt;
			}
			if (i < N - 1) {
				cnt = min(A[i], A[i + 1]);
				ans += cnt * (B + C);
				A[i] -= cnt;
				A[i + 1] -= cnt;
			}
		}

		ans += A[i] * B;
	}

	cout << ans << "\n";

	return 0;
}
