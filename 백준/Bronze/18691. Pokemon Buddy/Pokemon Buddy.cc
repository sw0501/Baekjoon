#include <bits/stdc++.h>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int g[4] = { 0,1,3,5 };

	for (int t = 0; t < T; t++) {
		int G, C, E;
		cin >> G >> C >> E;

		if (C >= E) {
			cout << 0 << "\n";
			continue;
		}

		cout << (E - C) * g[G] << "\n";
	}

}