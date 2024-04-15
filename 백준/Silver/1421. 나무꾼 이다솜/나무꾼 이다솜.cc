#include<iostream>
#include<string>
#include<vector>
#include<cmath>


using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, C, W;

	vector<int>tree;

	cin >> K >> C >> W;

	int maxL = -1;
	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		tree.push_back(n);
		maxL = (n > maxL ? n : maxL);
	}

	long long int answer = 0;
	for (int i = 1; i <= maxL; i++) {
		long long int tempCost = 0;
		for (int j = 0; j < tree.size(); j++) {

			int cnt = tree[j] / i;

			//판매 비용과 자르는데 드는 비용 계산
			int cut = max(0, cnt);

			if (tree[j] % i == 0)cut--;

			tempCost += max((long long int)0, (long long int)(cnt*i*W - cut*C));
		}
		answer = max((long long int)tempCost, answer);
	}

	cout << answer << "\n";

	return 0;
}