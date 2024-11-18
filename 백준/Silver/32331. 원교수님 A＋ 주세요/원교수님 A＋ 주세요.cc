#include<bits/stdc++.h>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	long long int X, Y;

	cin >> N >> M >> X >> Y;

	vector<long long int>score;

	int hNumber;
	long long int hMid, hFinal;
	cin >> hNumber >> hMid;
	hNumber /= 1000000;

	score.push_back(hMid);
	for (int i = 0; i < N-1; i++) {
		int number;
		long long int mid, final;
		cin >> number >> mid;
		final = Y - (X - mid);
		if (final < 0) {
			final = 0;
		}

		if(number/1000000 == hNumber)score.push_back(mid + final);
	}

	sort(score.begin(), score.end());
	reverse(score.begin(), score.end());

	if (M - 1 >= score.size()) {
		hFinal = 0;
	}
	else  hFinal = score[M-1] - hMid;

	if (hFinal < 0) {
		hFinal = 0;
	}
	
	if (hFinal > Y) {
		cout << "NO" << "\n";
	}
	else {
		cout << "YES" << "\n";
		cout << hFinal << "\n";
	}

	return 0;
}