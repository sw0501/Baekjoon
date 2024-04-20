#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

struct Point {
	int x, y;
};

Point list[10001];
int DP[10001] = { 0, };	//DP[i] i까지 기지국 연결 시 최솟값

bool compare(Point &p1, Point&p2) {
	if (p1.x == p2.x) {
		return p1.y < p2.y;
	}
	return p1.x < p2.x;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> list[i].x >> list[i].y;	
	}

	sort(list+1, list + N + 1,compare);

	//첫번째 기지국은 비용 0
	for (int i = 1; i <= N; i++) {
		int mH = 0;
		DP[i] = 1000000000;
		//앞의 박스들 이용하여 최솟값 계산
		for (int j = i; j >= 1; j--) {
			//높이 계산
			mH = max(mH, abs(list[j].y));
			DP[i] = min(DP[i], DP[j - 1] + max(2 * mH, list[i].x - list[j].x));
		}
	}

	cout << DP[N];

	return 0;
}