#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>

using namespace std;

int DP[101] = { 0, };		//높이 값 기준
int top[101] = { 0, };		//탑에 쌓인 인덱스
int c[101] = { 0, };	//탑에 쌓인 블록 개수


struct Brick {
	int number, area, height, weight;
};

Brick brick[101];

bool compare(Brick& b1, Brick& b2) {
	return b1.area < b2.area;
}

void DFS(int idx) {
	if (idx != 0) {
		DFS(top[idx]);
		cout << brick[idx].number << "\n";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int a, h, w;
		cin >> a >> h >> w;
		brick[i].number = i;
		brick[i].area = a;
		brick[i].height = h;
		brick[i].weight = w;		
	}

	sort(brick + 1, brick + N + 1, compare);

	int maxHeight = 0;
	int maxIdx = 0;

	//바닥 길이 순으로 이미 정렬
	for (int i = 1; i <= N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			//쌓을 수 있는 경우
			if (brick[i].weight > brick[j].weight) {
				if (DP[i] < DP[j] + brick[i].height) {

					DP[i] = DP[j] + brick[i].height;
					top[i] = j;

					c[i] = c[j] + 1;
				}
			}
		}
		if (maxHeight < DP[i]) {
			maxHeight = DP[i];
			maxIdx = i;
		}
	}

	//가장 높은 위치의 벽돌 개수 
	cout << c[maxIdx] << "\n";

	DFS(maxIdx);

	return 0;
}