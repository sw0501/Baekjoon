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

	for (int i = str.length()-1; i >= 0; i--) {
		if (str[i] == 'A')A.push(i);
		else if (str[i] == 'B')B.push(i);
	}

	int cnt = 0;

	//제일 뒤에서부터 탐색
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == 'B') {
			while (!A.empty() && A.front() >= i) {
				A.pop();
			}

			if (!A.empty() && A.front() < i) {

				

				//이미 제거한 A 삭제
				while (!A.empty() && str[A.front()] != 'A')A.pop();

				if (!A.empty()) {
					//문자 제거
					str[A.front()] = ' ';
					str[i] = ' ';
					A.pop();
					cnt++;
				}
			}
		}
		else if (str[i] == 'C') {
			while (!B.empty() && B.front() >= i) {
				B.pop();
			}

			if (!B.empty() && B.front() < i) {

				

				//이미 제거한 A 삭제
				while (!B.empty() && str[B.front()] != 'B')B.pop();

				if (!B.empty()) {
					//문자 제거
					str[B.front()] = ' ';
					str[i] = ' ';
					B.pop();
					cnt++;
				}
			}
		}
	}

	cout << cnt << "\n";
 
	return 0;
}