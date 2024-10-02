#include <bits/stdc++.h>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;

	cin >> str;

	//A,B 인덱스
	queue<int>A;
	queue<int>B;
	queue<int>C;

	for (int i = str.length()-1; i >= 0; i--) {
		if (str[i] == 'A')A.push(i);
		else if (str[i] == 'B')B.push(i);
		else if (str[i] == 'C')C.push(i);
	}

	int cnt = 0;
	while (!A.empty()) {
		if (!B.empty() && B.front() > A.front()) {
			B.pop();
			cnt++;
		}
		A.pop();
	}
	while (!B.empty()) {
		if (!C.empty() && C.front() > B.front()) {
			C.pop();
			cnt++;
		}
		B.pop();
	}

	cout << cnt << "\n";
 
	return 0;
}