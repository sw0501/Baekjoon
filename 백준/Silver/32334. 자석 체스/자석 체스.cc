#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;
const int MAX_D = 50;

int arr[1001][1001];
int prefixSum[1001][1001];

int N, D;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	// N, D 입력
	cin >> N >> D;

	//체스판 상태 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	//누적합 계산
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			prefixSum[i][j] = arr[i-1][j-1];
			prefixSum[i][j] += prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
		}
	}

	//최소 개수
	int minCnt = N * N;
	//해당 위치
	int x = -1, y = -1;

	//O(N^2)
	//누적합으로 자석이 놓여져있는 개수 체크
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//자석이 놓여있는 경우 다음 칸으로 이동
			if (arr[i - 1][j - 1])continue;

			//누적합 시작
			int sx = (i+D > N ? N : i+D);
			int sy = (j+D > N ? N : j+D);

			//누적합 끝
			int ex = (i - D < 1 ? 1 : i - D) - 1;
			int ey = (j - D < 1 ? 1 : j - D) - 1;

			int cnt = prefixSum[sx][sy] - prefixSum[ex][sy] - prefixSum[sx][ey] + prefixSum[ex][ey];

			// 처음 발견된 놓을 수 있는 위치인 경우
			if (cnt == 0) {
				cout << i << " " << j << "\n";
				return 0;
			}
			//더 적은 자석을 가져가는 위치인 경우
			else if (minCnt > cnt) {
				minCnt = cnt;
				x = i;
				y = j;				
			}
		}
	}

	cout << x << " " << y << "\n";
	cout << minCnt << "\n";

	return 0;
}