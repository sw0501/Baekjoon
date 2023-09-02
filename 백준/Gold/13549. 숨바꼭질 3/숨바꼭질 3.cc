#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int K;

int T[200001] = { 0, };
int D[200001] = { 0, };
int visit_BFS[200001] = { 0, };

void init();
void BFS(int N);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();


	return 0;
}

void init() {
	int N;
	cin >> N >> K;

	BFS(N);

}

void BFS(int N) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> point;
	point.push({ 0,N });
	D[N] = 1;
	while (!point.empty()) {
		int pos = point.top().second;
		point.pop();

		visit_BFS[pos] = 1;
		if (0 <= pos * 2 && pos * 2 <= 2 * K) {
			if (visit_BFS[pos + pos] == 0) {
				visit_BFS[pos + pos] = 1;
				T[pos + pos] = T[pos];
				//D[pos + pos] += D[pos];
				point.push({ T[pos], pos * 2 });
			}
			/*
			//K 재방문 시
			else if (T[pos + pos] == T[pos]) {
				D[pos + pos] += D[pos];
			}
			*/
		}
		if (0 <= pos - 1) {
			if (visit_BFS[pos - 1] == 0) {
				visit_BFS[pos - 1] = 1;
				T[pos - 1] = T[pos] + 1;
				//D[pos - 1] += D[pos];
				point.push({ T[pos - 1], pos - 1 });
			}
			/*
			//K 재방문 시
			else if (T[pos - 1] == T[pos] + 1) {
				D[pos - 1] += D[pos];
			}
			*/
		}
		if (0 <= pos + 1 && pos + 1 <= 2 * K) {
			if (visit_BFS[pos + 1] == 0) {
				visit_BFS[pos + 1] = 1;
				T[pos + 1] = T[pos] + 1;
				//D[pos + 1] += D[pos];
				point.push({ T[pos + 1], pos + 1 });
			}
			/*
			//K 재방문 시
			else if (T[pos + 1] == T[pos] + 1) {
				D[pos + 1] += D[pos];
			}
			*/
		}
	}

	cout << T[K] << "\n";
}
