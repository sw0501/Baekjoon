#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

deque<int> dq;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num, element;
	string op;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> op;
		if (op == "push") {
			cin >> element;
			dq.push_back(element);
		}
		else if (op == "pop") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (op == "size") {
			cout << dq.size() << "\n";
		}
		else if (op == "empty") {
			if (dq.empty()) {
				cout << 1 << "\n";
			}
			else cout << 0 << "\n";
		}
		else if (op == "front") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else cout << dq.front() << "\n";
		}
		else if (op == "back") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else cout << dq.back() << "\n";
		}
		
	}
	


	return 0;
}