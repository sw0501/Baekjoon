#include<iostream>
#include<stack>
#include<vector>

using namespace std;

string str;
string bomb;

stack<char>st;
stack<char>temp;

int main() {

	cin >> str >> bomb;

	int len = bomb.length() - 1;

	for (int i = 0; i < str.length(); i++) {

		st.push(str[i]);

		if (st.top() == bomb[len]) {
			int flag = 1;
			//마지막 글자는 찾았으니까 뒤에서 2번째부터 찾기
			for (int j = len; j >= 0; j--) {
				if (st.empty()||st.top() != bomb[j]) {
					flag = 0;
					break;
				}
				temp.push(st.top());
				st.pop();
			}
			while (!temp.empty()) {
				if(flag==0)st.push(temp.top());
				temp.pop();
			}
		}
	}

	if (st.empty()) {
		cout << "FRULA" << "\n";
		return 0;
	}

	else {

		vector<char>V;

		while (!st.empty()) {
			V.push_back(st.top());
			st.pop();
		}

		for (int i = V.size()-1; i>=0; i--) {
			cout << V[i];
		}
	}
	

	return 0;
}