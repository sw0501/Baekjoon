#include<iostream>

using namespace std;

int num[1000];
int N, t;

void DFS(int a, int c, int s);

int main() {

	cin >> N;

	if (N > 1023) {
		cout << -1 << "\n";
		return 0;
	}
	else if (N <= 10) {
		cout << N - 1 << "\n";
	}

	else {
		//자리수를 늘려가면서 
		t = 10;
		for (int i = 2; i < 1000; i++) {
			//시작 자리수, 전체 자리수, 0~9까지
			DFS(0, i, 9);
		}
	}
	

	return 0;
}

void DFS(int a, int c, int s) {
	if (a == c) {
		t++;
		if (t == N) {
			for (int i = 0; i < a; i++) {
				cout << num[i];
			}
			cout << "\n";
		}
	}
	else if (a > c) {
		return;
	}
	else {
		for (int i = 0; i <= s; i++) {
			if (i == 0 && a + 1 != c) {
				continue;
			}
			num[a] = i;
			DFS(a + 1, c, i-1);
		}
	}
}
