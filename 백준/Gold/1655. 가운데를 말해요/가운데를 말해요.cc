#include <iostream>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> M;
priority_queue<int,vector<int>,less<int>> m;

int main(){

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N,num;
	cin >> N;

	cin >> num;
	cout << num << "\n";
	M.push(num);

	for (int i = 1; i < N; i++) {
		cin >> num;
		
		//홀수 입력
		if (M.size() == m.size()) {
			m.push(num);
			M.push(m.top());
			m.pop();

			cout << M.top() << "\n";
		}
		else {
			M.push(num);
			m.push(M.top());
			M.pop();

			cout << m.top() << "\n";
		}
	}

	return 0;
}
