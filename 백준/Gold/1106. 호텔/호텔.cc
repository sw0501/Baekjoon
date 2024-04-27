#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>

using namespace std;

int C, N;

struct Hotel {
	int price, num;
};

vector<Hotel>v;
int sum[1001];

int DFS(int cnt) {
	int m = 100 * 1000;
	int cost;

	if (cnt <= 0) {
		return 0;
	}

	else if (sum[cnt] > 0) {
		return sum[cnt];
	}

	else {
		for (int i = 0; i < N; i++) {
			cost = DFS(cnt - v[i].num) + v[i].price;
			m = min(cost, m);
		}
		sum[cnt] = m;

		return m;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C >> N;

	for (int i = 0; i < N; i++) {
		int p, n;
		cin >> p >> n;
		v.push_back({ p,n });
	}

	cout << DFS(C);

	return 0;
}