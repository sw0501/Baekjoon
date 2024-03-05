#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

long long int DP[100001][4][2] = {0,};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	DP[1][1][1] = 1;	//1
	DP[2][1][0] = 1;	//1 + 1
	DP[2][2][1] = 1;	//2
	DP[3][1][0] = 1;	//1 + 2
	DP[3][1][1] = 1;	//1 + 1 + 1
	DP[3][2][0] = 1;	//1 + 2
	DP[3][3][1] = 1;	//3

	for (int i = 4; i <= 100000; i++) {
		
		DP[i][1][0] = (DP[i - 1][1][1] + DP[i - 1][2][1] + DP[i - 1][3][1]) % 1000000009;
		DP[i][1][1] = (DP[i - 1][1][0] + DP[i - 1][2][0] + DP[i - 1][3][0]) % 1000000009;

		DP[i][2][0] = (DP[i - 2][1][1] + DP[i - 2][2][1] + DP[i - 2][3][1]) % 1000000009;
		DP[i][2][1] = (DP[i - 2][1][0] + DP[i - 2][2][0] + DP[i - 2][3][0]) % 1000000009;

		DP[i][3][0] = (DP[i - 3][1][1] + DP[i - 3][2][1] + DP[i - 3][3][1]) % 1000000009;
		DP[i][3][1] = (DP[i - 3][1][0] + DP[i - 3][2][0] + DP[i - 3][3][0]) % 1000000009;
	}

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		cout << (DP[N][1][1] + DP[N][2][1] + DP[N][3][1]) % 1000000009 << " " << (DP[N][1][0] + DP[N][2][0] + DP[N][3][0]) % 1000000009 << "\n";
	}

	return 0;
}