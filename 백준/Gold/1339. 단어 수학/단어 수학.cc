#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

int main() {

	int num[26] = { 0, };
	string str[10];
	pair<int, char>value[26];

	for (int i = 0; i < 26; i++) {
		value[i] = { 0,'A' + i };
	}

	int N;
	cin >> N;

	
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	//알파벳이 차지하는 볼륨을 계산하여 수 배정
	for (int i = 0; i < N; i++) {
		int digit = 1;
		for (int j = str[i].length() - 1; j >= 0; j--) {
			value[(int)(str[i][j] - 'A')].first += digit;
			digit *= 10;
		}
	}

	sort(value, value + 26);
	
	int n = 9;
	for (int i = 25; i >=0; i--) {
		if (value[i].first != 0) {
			num[(int)(value[i].second - 'A')] = n--;
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < str[i].length(); j++) {
			temp *= 10;
			temp += num[(int)(str[i][j] - 'A')];
		}
		answer += temp;
	}

	cout << answer << "\n";

	return 0;
}