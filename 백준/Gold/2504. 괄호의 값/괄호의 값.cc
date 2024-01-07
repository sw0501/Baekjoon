#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main(){

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	int ans = 0;
	int temp = 1;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			temp *= 2;
			st.push(str[i]);
		}
		else if (str[i] == '[') {
			temp *= 3;
			st.push(str[i]);
		}
		else if (str[i] == ')') {
			if (st.empty() || st.top() != '(') {
				while (!st.empty()) {
					st.pop();
				}
				cout << "0";
				return 0;
			}
			else if (str[i-1]=='(') {
				ans += temp;
				temp /= 2;
				st.pop();
			}
			else {
				temp /= 2;
				st.pop();
			}
		}
		else if (str[i] == ']') {
			if (st.empty() || st.top() != '[') {
				while (!st.empty()) {
					st.pop();
				}
				cout << "0";
				return 0;
			}
			else if (str[i - 1] == '[') {
				ans += temp;
				temp /= 3;
				st.pop();
			}
			else {
				temp /= 3;
				st.pop();
			}
			
		}
	}

	if (!st.empty()) {
		while (!st.empty()) {
			st.pop();
		}
		cout << "0";
		return 0;
	}
	else {
		cout << ans << "\n";
	}

	return 0;
}