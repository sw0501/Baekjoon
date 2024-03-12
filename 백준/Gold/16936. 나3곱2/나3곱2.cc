#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
#include<limits.h>
#include<cmath>
#include<string>
#include<stack>

using namespace std;

vector<long long int> arr;
int visit[100] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	//제일 작은 수는 무조건 나누기 당함
	deque<long long int>answer;
	answer.push_back(arr[0]);
	visit[0] = 1;

	int flag = 1;
	while (flag) {
		flag = 0;
		//제일 작은 수 기준 뒤
		for (int i = 0; i < N; i++) {
			if (visit[i])continue;
			if (answer.back() % 3 == 0 && answer.back() / 3 == arr[i]) {
				answer.push_back(arr[i]);
				visit[i] = 1;
				flag = 1;
			}
			else if (answer.back() * 2 == arr[i]) {
				answer.push_back(arr[i]);
				visit[i] = 1;
				flag = 1;
			}
		}
	}
	
	flag = 1;
	while(flag) {
		flag = 0;
		//제일 작은 수 기준 앞
		for (int i = 0; i < N; i++) {
			if (visit[i])continue;
			if (answer.front() * 3 == arr[i]) {
				answer.push_front(arr[i]);
				visit[i] = 1;
				flag = 1;
			}
			else if (answer.front() % 2 == 0 && answer.front() / 2 == arr[i]) {
				answer.push_front(arr[i]);
				visit[i] = 1;
				flag = 1;
			}
		}
	}
	
	
	while (!answer.empty()) {
		cout << answer.front() << " ";
		answer.pop_front();
	}

	return 0;
}