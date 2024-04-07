#include<iostream>
#include<string>

using namespace std;

string ans = "";
string answer;
string map[1001];

int start[1001] = { 0, };
int dest[1001] = { 0, };

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, N;
	cin >> K >> N;

	cin >> ans;

	//? 높이
	int idx = -1;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		if (map[i][0] == '?')idx = i;
	}

	//위쪽 길목
	for (int i = 0; i < K; i++) {
		int pos = i;
		for (int j = 0; j < idx; j++) {
			//- 위치라면 오른쪽으로 이동
			if (pos < K - 1 && map[j][pos] == '-') {
				pos++;
			}
			//왼쪽 길이 있는 경우 왼쪽으로 이동
			else if (pos > 0 && map[j][pos - 1] == '-') {
				pos--;
			}
		}
		start[pos] = i;
	}

	//아래 길목 
	for (int i = 0; i < K; i++) {
		int pos = i;
		for (int j = N - 1; j > idx; j--) {
			//- 위치라면 오른쪽으로 이동
			if (pos > 0 && map[j][pos - 1] == '-') {
				pos--;
			}
			
			//왼쪽 길이 있는 경우 왼쪽으로 이동
			else if (pos < K - 1 && map[j][pos] == '-') {
				pos++;
			}
		}
		dest[pos] = (int)(ans[i] - 'A');
	}

	int flag = 0;

	/*
	for (int i = 0; i < K; i++) {
		cout << (char)(start[i]+'A');
	}
	cout << "\n";
	for (int i = 0; i < K; i++) {
		cout << (char)(dest[i] + 'A');
	}
	cout << "\n";
	*/


	//길찾기
	for (int i = 0; i < K; i++) {
		//같은 위치인 경우
		if (start[i] == dest[i]) {
			if(i<K-1)answer += "*";
		}
		else if (start[i] == dest[i + 1]) {
			if (i < K - 1)answer += "-";
		}
		//일치하지 않는 경우
		
		else if (i > 0 && start[i] == dest[i - 1] && answer[i - 1] == '-') {
			if (i < K - 1)answer += "*";
		}
		else{
			flag = 1;
			break;
		}
	}	

	if (flag) {
		for (int i = 0; i < K - 1; i++) {
			cout << 'x';
		}
	}
	else {
		cout << answer << "\n";
	}

	return 0;
}