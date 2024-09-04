#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;

unordered_set<int>s;

//합
int arr[2000001] = { 0, };

int main() {

	int S;
	cin >> S;

	for (int i = 0; i < S; i++) {
		int num;
		cin >> num;

		arr[num] = 1;
		unordered_set<int> temp;
		temp.insert(num);
		for (auto it:s) {
			arr[it + num] = 1;
			temp.insert(it + num);
		}
		for (auto it : temp) {
			s.insert(it);
		}
	}
	for (int i = 1; i <= 2000000; i++) {
		if (!arr[i]) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}