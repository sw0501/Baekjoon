#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

string s1;
string s2;
int dp[1001][1001] = { 0, };

stack<char>c;
int x=0, y=0;

void init();

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	init();


	return 0;
}

void init() {

	int M = 0;
	string ms = "";

	cin >> s1 >> s2;

	//s1과 s2를 비교하면서 해당 문자가 들어있는지 확인 후 DP에 저장
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i][j - 1];
				}
			}
			if (M < dp[i][j]) {
				M = max(M, dp[i][j]);
				x = i;
				y = j;
			}
		}
	}

	/*
	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	cout << M << "\n";

	if (M != 0) {
		x = s1.size();
		y = s2.size();
		while (1) {
			if (dp[x][y] == dp[x - 1][y]) {
				x--;
			}
			else if (dp[x][y] == dp[x][y - 1]) {
				y--;
			}
			else {
				c.push(s2[y - 1]);
				x--;
				y--;
			}
			if (x == 0 || y == 0) {
				break;
			}
		}
		while (!c.empty()) {
			cout << c.top();
			c.pop();
		}
	}
	
}
