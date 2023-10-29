#include<iostream>
#include<cmath>

using namespace std;

int INF = 1000000000;
int city[101][101] = { 0, };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);

	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			city[i][j] = INF;
		}
	}

	//자기 자신은 비용 0으로 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(i==j)city[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a][b] = min(city[a][b],c);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				city[i][j] = min(city[i][j],city[i][k] + city[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//갈 수 없는 곳이라면
			if (city[i][j] == INF)cout << 0 << " ";
			else cout << city[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}