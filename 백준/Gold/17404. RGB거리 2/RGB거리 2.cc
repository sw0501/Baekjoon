#include<iostream>
#include<algorithm>

using namespace std;

int house[1001][3] = { 0, };

int main() {

	int N;
    int ans = 1000001;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}

    for (int i = 0; i <= 2; i++) {
        int dp[1001][3] = { 0, };
        for (int j = 0; j <= 2; j++) {
            if (j == i) dp[1][i] = house[1][i];
            else dp[1][j] = 1000001;
        }
        for (int i = 2; i <= N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + house[i][2];
        }
        for (int j = 0; j <= 2; j++) {
            if (j == i) continue;
            ans = min(ans, dp[N][j]);
        }
    }

    cout << ans << "\n";

	return 0;
}