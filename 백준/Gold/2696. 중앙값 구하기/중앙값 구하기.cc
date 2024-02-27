#include <bits/stdc++.h>

using namespace std;

void init();

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	return 0;
}

struct compare1 {
	bool operator ()(int &a, int &b) {
		return a > b;
	}
};

struct compare2 {
	bool operator ()(int &a, int &b) {
		return a < b;
	}
};

void init() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int cnt = 0;
		int N;
		cin >> N;

		priority_queue<int, vector<int>, compare1>asc;	//큰 수 저장
		priority_queue<int, vector<int>, compare2>desc;	//작은 수 저장
		vector<int>ans;
		int num;
		cin >> num;

		cnt++;
		desc.push(num);
		ans.push_back(num);

		if (N == 1) {
			cout << cnt << "\n" << num << "\n";
			continue;
		}

		cin >> num;

		if (num > desc.top()) {
			asc.push(num);
		}
		else {
			asc.push(desc.top());
			desc.pop();
			desc.push(num);
		}

		for (int i = 3; i <= N; i++) {
			cin >> num;

			if (num > asc.top()) {
				if (asc.size() == desc.size()) {
					asc.push(num);
				}
				//asc top을 desc에 저장
				else{
					desc.push(asc.top());
					asc.pop();
					asc.push(num);
				}
			}
			else {
				//desc top asc에 저장
				if (asc.size()==desc.size()) {
					desc.push(num);
					asc.push(desc.top());
					desc.pop();
				}
				//desc가 적을 때
				else {
					desc.push(num);
				}
			}
			if (i % 2 == 1) {
				cnt++;
				ans.push_back(asc.top());
			}
		}

		cout << cnt;
		for (int i = 0; i < ans.size(); i++) {
			if (i % 10 == 0)cout << "\n";
			cout << ans[i] << " ";
		}
	}
}