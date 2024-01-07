#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

stack<char> st;
queue<char> q;

int main(){

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	getline(cin, str);

	//태그 확인
	int tag = 0;
	for (int i = 0; i < str.length(); i++) {
		if (tag) {
			q.push(str[i]);
			if (str[i] == '>') {
				while (!q.empty()) {
					cout << q.front();
					q.pop();
				}
				tag = 0;
			}
		}
		else {
			if (str[i] == '<') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				tag = 1;
				q.push(str[i]);
			}
			else if (str[i] == ' ') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << str[i];
			}
			else {
				st.push(str[i]);
			}
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}