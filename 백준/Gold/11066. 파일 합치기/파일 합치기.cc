#include<iostream>

using namespace std;

int T,K;
int DP[501][501] = { 0, };
int F[501] = { 0, };
int sum[501] = { 0, };

int main() {

	//테스트 개수 입력
	cin >> T;

	for (int t = 0; t < T; t++) {

		//파일 개수 입력
		cin >> K;

		//파일 크기 입력
		for (int i = 1; i <= K; i++) {
			cin >> F[i];
			//누적합 계산
			sum[i] = sum[i - 1] + F[i];
		}

		//i => 파일 정리 범위
		for (int i = 1; i <= K; i++) {
			//j => 파일 정리 시작 지점 , i + j => 파일 정리 끝 부분
			for (int j = 1; j <= K - i; j++) {
				//처음 파일 정리 최소값 초기화
				DP[j][i + j] = 1000000000;
				//k => 구분 범위
				for (int k = j; k < i + j; k++) {
					//시작 지점 부터 끝 지점 까지 파일 정리 최소값 구하기

					//파일 정리 최소값 = min (현재 값, 구분 지점 1까지의 최소값 + 구분 지점 2까지의 최소값 + 끝 부분까지의 파일 합 - 포함되지 안는 첫 부분
					DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}

		cout << DP[1][K] << "\n";
	}

	


	return 0;
}