#include <iostream>
#include <stack>
#include <climits>

using namespace std;

stack<char> raser;

int main(){

	string str;
	cin >> str;

	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		//레이저인지 확인
		if (str[i] == '(') {
			//레이저인 경우
			if (str[i + 1] == ')') {
				//들어있는 막대의 수 만큼 더하기
				ans += raser.size();
				i++;
			}
			//막대인 경우
			else {
				raser.push('(');
			}
		}
		//쇠막대기 끝나는 지점인 경우
		else {
			raser.pop();
			ans++;
		}
	}
	cout << ans << "\n";

	return 0;
}