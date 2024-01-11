#include<iostream>

using namespace std;

int main() {

	string str;

	cin >> str;

	int ans = 0;
	for (int i = 0; i <= (int)(str.length() - 4); i++) {
		if (str[i + 3] == '\0')break;
		if (str[i] == 'D' && str[i + 1] == 'K' && str[i + 2] == 'S' && str[i + 3] == 'H') {
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}