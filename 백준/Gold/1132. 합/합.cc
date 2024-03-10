#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
#include<limits.h>
#include<cmath>
#include<string>

using namespace std;

string str[51];
pair<long long int,int> num[10];
int isF[10] = { 0, };
long long int idx[10];

bool compare(const pair<long long int, int> &a, const pair<long long int, int> &b) {
	return a.first > b.first;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < 10; i++) {
		idx[i] = -1;
	}

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	//첫 자리
	for (int i = 0; i < 10; i++) {
		num[i].first = 0;
		num[i].second = i;
	}

	for (int i = 0; i < N; i++) {
		long long int k = 1;
		isF[str[i][0] - 'A'] = 1;
		for (int j = str[i].length()-1; j >= 0; j--) {
			//자릿수 더해주기
			num[str[i][j]-'A'].first += k;
			k *= 10;
		}
	}


	sort(num, num + 10, compare);

	//0부터 먼저 박고 시작
	for (int i =9; i >=0; i--) {
		//시작하는 수가 아닌 것 중 가장 작은 수에게 0 할당
		if (isF[num[i].second] == 0) {
			idx[num[i].second] = 0;
			break;
		}
	}

	int number = 9;
	for (int i = 0; i < 10; i++) {
		//이미 할당된 수 제외
		if (idx[num[i].second] >= 0) {
			continue;
		}
		idx[num[i].second] = number--;
	}

	long long int answer = 0;
	for (int i = 0; i < N; i++) {
		long long int temp = 0;
		for (int j = 0; j < str[i].length(); j++) {
			temp *= 10;
			temp += idx[str[i][j] - 'A'];
		}
		answer += temp;
	}

	cout << answer << "\n";

	return 0;
}