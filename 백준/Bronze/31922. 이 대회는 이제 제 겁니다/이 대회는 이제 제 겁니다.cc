#include<bits/stdc++.h>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A,P,C;
    cin >> A >> P >> C;
    
    cout << max(A+C,P);

	return 0;
}