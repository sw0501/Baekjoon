#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int H[1000001] = { 0, };

int main() {

	int N;
	int cnt = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		
		//시작 화살
		if (H[num + 1] == 0) {
			H[num]++;
			cnt++;
		}
		else {
			H[num + 1]--;
			H[num]++;
		}
		
	}

	cout << cnt << "\n";

	return 0;
}