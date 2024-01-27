#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int A[1000001] = { 0, };
int ck[1000001] = { 0, };
int NGF[1000001] = { 0, };
stack<pair<int, int>> st;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		ck[A[i]]++;
	}

	for (int i = 0; i < N; i++) {
		while (!st.empty() && ck[A[i]] > st.top().second) {
			int idx = st.top().first;
			st.pop();
			NGF[idx] = A[i];
		}
		st.push({ i,ck[A[i]] });
	}

	for (int i = 0; i < N; i++) {
		if (NGF[i] == 0) {
			NGF[i] = -1;
		}
		cout << NGF[i] << " ";
	}

	return 0;
}