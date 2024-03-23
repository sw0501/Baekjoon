#include<iostream>
#include<unordered_map>
#include<queue>
#include<unordered_set>

using namespace std;

int c;
string str;
int cnt = 0;

int decimal[10000000] = { 0, };
unordered_set<int>s;
int visit[7] = { 0, };

void comb(int num) {
	for (int i = 0; i < str.length(); i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			if (decimal[num * 10 + (int)(str[i] - '0')] == 0 && s.find(num * 10 + (int)(str[i] - '0')) == s.end()) {
				cnt++;
				s.insert(num * 10 + (int)(str[i] - '0'));
			}
			comb(num * 10 + (int)(str[i] - '0'));
			visit[i] = 0;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c;

	decimal[0] = 1;
	decimal[1] = 1;
	for (int i = 2; i < 10000000; i++) {
		if (decimal[i])continue;
		for (int j = i+i; j < 10000000; j += i) {
			decimal[j] = 1;
		}
	}

	for (int i = 0; i < c; i++) {
		s.clear();
		cnt = 0;
		cin >> str;
		comb(0);
		cout << cnt << "\n";
	}

	return 0;
}