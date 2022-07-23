#include<iostream>
#include<queue>

using namespace std;



int main() {

	int N;

	priority_queue<int, vector<int>, greater<int>>pq;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int card;
		cin >> card;
		pq.push(card);
	}

	if (pq.size() == 1) {
		cout << 0 << "\n";
	}

	else {
		int cnt = 0;
		while (!pq.empty()) {
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();

			cnt += a + b;

			if (pq.empty()) {
				cout << cnt << "\n";
				break;
			}
			else pq.push(a + b);
		}
	}

	return 0;
}