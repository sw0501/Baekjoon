#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> block[51];

int DP[51][1001] = {0,};

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, H;

	cin >> N >> M >> H;
	for (int i = 0; i < N; i++) {
		DP[i][0] = 1;
	}

	cin.ignore();

	for (int i = 1; i <= N; i++) {
		string str;
		getline(cin, str);

		int temp = 0;
		int cnt = 0;
		for (int j = 0; j <= str.length(); j++) {
			if (str[j] == ' ' || str[j] == '\0') {
				block[i].push_back(temp);
				temp = 0;
			}
			else {
				temp *= 10;
				temp += (int)(str[j] - '0');
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= H; j++) {
			for (int k = 0; k < block[i].size(); k++) {
				if (j >= block[i][k]) {
					DP[i][j] = (DP[i][j] + DP[i - 1][j - block[i][k]]) % 10007;
				}
			}
			DP[i][j] = (DP[i][j] + DP[i - 1][j]) % 10007;
		}
	}

	cout << DP[N][H];

	return 0;
}