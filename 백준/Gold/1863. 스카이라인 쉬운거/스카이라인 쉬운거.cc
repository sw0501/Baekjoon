#include <bits/stdc++.h>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<int> st;

	int N;

	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		if (!st.empty()) {
			if (st.top() < y) {
				st.push(y);
			}
			else if (st.top() >= y) {
				while (!st.empty() && st.top() >= y) {
					//cout << st.top() << "\n";
					if (y != st.top()) {
						cnt++;
						//cout << st.top() << "\n";
					}
					st.pop();
				}
				st.push(y);
			}
		}
		else {
			if(y>0)st.push(y);
		}
	}


	while (!st.empty()) {
		if (st.top() > 0) {
			cnt++;
			//cout << st.top() << "\n";
		}
		
		st.pop();
	}	
	
	cout << cnt << "\n";
 
	return 0;
}