#include<iostream>
#include<queue>

using namespace std;

long long int arr[1000001] = { 0, };

long long int m, M;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> M;

	//가장 작은 제곱수로 나누어 떨어지는 값 찾기
	for (long long int i = 2; i * i <= M; i++) {
		long long int num = m / (i * i);
		if (num * (i * i) < m) {
			num++;
		}
		num *= (i * i);

		//cout << num << "\n";
		for (long long int j = num; j <= M; j += (i * i)) {
			arr[j - m] = 1;
		}
	}

	long long int cnt = 0;
	for (long long int j = m; j <= M; j++) {
		if (arr[j - m] == 0) {
			cnt++;
		}
	}
	
	cout << cnt << "\n";

	return 0;
}