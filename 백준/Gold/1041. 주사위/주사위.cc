#include <bits/stdc++.h>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	/*
	int N, M;
	vector<int>book;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int pos;
		cin >> pos;

		book.push_back(pos);
	}
	*/

	long long int N;
	cin >> N;

	long long int dice[6] = { 0, };

	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
	}

	//각 모서리에 있는 주사위 (3면) 8개
	//가장자리에 있는 주사위 (2면) : 전체 - 3면 - 1면
	//한 면만 보이는 주사위 (1면) 6 * (N-2)^2

	long long int dice1 = 1000000;
	for (int i = 0; i < 6; i++) {
		dice1 = min(dice1, dice[i]);
	}

	long long int dice2 = 2000000;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (j == i || j == 5 - i)continue;
			dice2 = min(dice2, dice[i] + dice[j]);
		}
	}

	long long int dice3 = 3000000;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (j == i || j == 5 - i)continue;
			for (int k = 0; k < 6; k++) {
				if (k == i || k == j || k == 5 - i || k==5-j)continue;
				dice3 = min(dice3, dice[i] + dice[j] + dice[k]);
			}
		}
	}

	long long int ans = 0;
	if (N == 1) {	
		int M = 0;
		for (int i = 0; i < 6; i++) {
			ans += dice[i];
			M = max(M, (int)dice[i]);
		}
		ans -= M;
	}
	else {

		ans += dice3 * 4;

		ans += dice2 * (8 * N - 12);

		ans += dice1 * (5 * N * N - 16 * N + 12);
	}

	cout << ans << "\n";
 
	return 0;
}