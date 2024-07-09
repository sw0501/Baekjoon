#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str[3];
	for (int i = 0; i < 3; i++) {
		cin >> str[i];
	}

	//3개 모두 문자가 나올 순 없음
	
	int ans = 0;

	//1

	for (int i = 2; i >= 0; i--) {
		if (str[i][0] >= '0' && str[i][0] <= '9') {
			for (int j = 0; j < str[i].length(); j++) {
				ans *= 10;
				ans += str[i][j] - '0';
			}

			ans += 3 - i;
			break;
		}
	}
	
	if (ans % 3 == 0 && ans % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (ans % 3 == 0) {
		cout << "Fizz";
	}
	else if (ans % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << ans;
	}


	return 0;
}