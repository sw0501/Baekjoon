#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

pair<int,int> A[500001];
int N;

int main(){

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	
	cin >> N;
	
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		A[i].first = num;
		A[i].second = i;
	}

	sort(A, A + N);

	int M = -1;
	for (int i = 0; i < N; i++) {
		int diff = A[i].second - i;
		M = max(M, diff);
	}
	
	cout << M+1 << "\n";

	return 0;
}
