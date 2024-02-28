#include<iostream>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

int arr[5000001] = { 0, };
int D[5000001] = { 0, };

struct Pair {
	int num, idx;
};

struct compare {
	bool operator()(const Pair &a,const Pair &b) {
		return a.num > b.num;
	}
};
priority_queue<Pair, vector<Pair>,compare>pq;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;

	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	//1 ~ L까지 최솟값
	for (int i = 1; i <= L; i++) {
		pq.push({ arr[i],i });
		D[i] = pq.top().num;
	}

	//L + 1 ~ N까지 최솟값
	for (int i = L + 1; i <= N; i++) {
		//이전 인덱스 최솟값 제거
		while (!pq.empty() && pq.top().idx < i - L + 1) {
			pq.pop();
		}
		//현재 수 추가
		pq.push({ arr[i],i });
		D[i] = pq.top().num;
	}

	for (int i = 1; i <= N; i++) {
		cout << D[i] << " ";
	}
	cout << "\n";

	return 0;
}