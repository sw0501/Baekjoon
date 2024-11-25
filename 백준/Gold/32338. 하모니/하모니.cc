#include<bits/stdc++.h>

using namespace std;

//수련
struct Training {
	int M, W, V;
};

Training training[101];

//T / N / -K ~ K
int DP[101][1001][203] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T >> N;

	//DP 초기화
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 1000; j++) {
			for (int k = -101; k <= 101; k++) {
				//수련 불가능
				DP[i][j][k + 100] = -1;
			}
		}
		DP[i][0][101] = 0;
	}

	//수련 입력
	for (int i = 1; i <= T; i++) {
		int M, W, V;
		cin >> M >> W >> V;

		training[i].M = M;
		training[i].V = V;
		training[i].W = W;
	}

	//수련 조회
	for (int i = 1; i <= T; i++) {
		int W = training[i].W;
		int M = training[i].M;
		int V = training[i].V;

		//시간 
		for (int j = 1; j <= N; j++) {
			//조화 합
			for (int k = -T; k <= T; k++) {

				DP[i][j][k + 101] = DP[i - 1][j][k + 101];

				//더 높은 기력을 얻을 수 있는 경우
				//해당 수련이 가능한 경우
				if (j >= W && DP[i - 1][j - W][k - M + 101] != -1) {
					int v = DP[i - 1][j - W][k - M + 101] + V;
					//더 높은 기력을 가질 수 있는 수련 선택
					DP[i][j][k + 101] = max(DP[i][j][k + 101], v);
				}
			}
		}
	}

	//최대 기력
	int maxValue = 0;
	//조화 차이 최소
	int minHarmony = 0;

	//수련 시간 별 조회
	for (int i = 1; i <= N; i++) {
		//조화 차이별 조회
		for (int j = -T; j <= T; j++) {
			//수련이 불가능한 경우 제외
			if (DP[T][i][j + 101] == -1)continue;

			//기력 
			int value = DP[T][i][j + 101];

			//조화를 이룬 경우 기력 2배 증가
			if (j == 0) {
				value *= 2;
			}

			//가치 비교
			if (value > maxValue) {
				maxValue = value;
				minHarmony = j;
			}
			//가치가 같은 경우 조화 차이 비교
			else if (value == maxValue) {
				if (abs(minHarmony) > abs(j)) {
					minHarmony = j;
				}
				else if(abs(minHarmony) == abs(j) ){
					minHarmony = abs(j);
				}
			}
		}
	}

	//출력
	cout << minHarmony << " " << maxValue << "\n";

	return 0;
}