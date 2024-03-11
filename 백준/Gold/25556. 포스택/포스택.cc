#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
#include<limits.h>
#include<cmath>
#include<string>
#include<stack>

using namespace std;

stack<int>st[4];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		
		int flag = 1;
		for (int j = 0; j < 4; j++) {	
			if (st[j].empty() || st[j].top() < num) {
				st[j].push(num);
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << "NO" << "\n";
			return 0;
		}
	}

	int num = 1000001;
	int flag = 1;

	while (!(st[0].empty() && st[1].empty() && st[2].empty() && st[3].empty())){
		//제일 큰 수 꺼내기
		int max = -1;
		int idx = -1;
		for (int i = 0; i < 4; i++) {
			if (!st[i].empty() && st[i].top() > max) {
				max = st[i].top();
				idx = i;
			}
		}
		if (max != -1 && num > max) {
			num = max;
			st[idx].pop();
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}



	return 0;
}