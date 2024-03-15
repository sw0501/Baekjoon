#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
#include<limits.h>
#include<cmath>
#include<string>
#include<stack>
#include<unordered_map>


using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	unordered_map<string, int> book;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (book.find(str) == book.end()) {
			book.insert({ str,0 });
		}
		else {
			book[str]++;
		}
	}

	string name;
	int max = -1;
	for (auto it : book) {
		if (it.second > max) {
			name = it.first;
			max = it.second;
		}
		else if (it.second == max && it.first.compare(name) < 0) {
			name = it.first;
		}
	}

	cout << name << "\n";
	

	return 0;
}