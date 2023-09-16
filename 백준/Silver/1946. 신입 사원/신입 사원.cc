#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int ck[100000] = { 0, };

bool compare(pair<int, int>a, pair<int, int>b) {
	return a.first < b.first;
}

int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		vector<pair<int, int>> arr;
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			arr.push_back({ a,b });
		}
		sort(arr.begin(), arr.end(), compare);
		int cnt = 1;

		int tmp = 0;
		for (int i = 1; i < N; i++) {
			if (arr[tmp].second > arr[i].second) {
				cnt++;
				tmp = i;
				
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}