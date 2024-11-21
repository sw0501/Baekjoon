#include <bits/stdc++.h>
using namespace std;

//자신보다 작거나 같은 피보나치 수
int num[1000001] = { 0, };

//정답 수
int ans[1000001] = { 0, };

int Fibo[32] = { 0, };

int main() {

	int N;
	cin >> N;

	
	Fibo[0] = 0;
	Fibo[1] = 1;

	for(int n=2;n<=31;n++){
		Fibo[n] = Fibo[n - 1] + Fibo[n - 2];
		if(Fibo[n] <= 1000000)num[Fibo[n]] = Fibo[n];
	}

	//N이 피보나치 수 일 때 게임 이길 수 없음
	//자신보다 작은 피보나치 수

	num[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (num[i] == i)continue;

		int j = 1;
		while (Fibo[j] < i) {
			j++;
		}

		num[i] = num[i-Fibo[j-1]];
	}

	for (int i = 1; i <= 1000000; i++) {
		if (num[i] == i)ans[i] = -1;
		else {
			int j = 1;
			while (Fibo[j] < i) {
				j++;
			}
			ans[i] = num[i % Fibo[j - 1]];
		}
	}

	cout << ans[N] << "\n";
}