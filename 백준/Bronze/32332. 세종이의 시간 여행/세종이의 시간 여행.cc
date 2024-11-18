#include<bits/stdc++.h>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//과거 시간
	int Y, M, D;
	double lo, la;

	//현재 시간
	int Y0, M0, D0;
	double lo0, la0;

	//미래 시간
	int Y1, M1, D1;
	double lo1, la1;

	//입력
	cin >> Y0 >> M0 >> D0;
	cin >> lo0 >> la0;

	cin >> Y1 >> M1 >> D1;
	cin >> lo1 >> la1;

	//목적 날짜 및 위치 계산
	Y = Y0 - (Y1 - Y0);
	M = M0 - (M1 - M0);
	D = D0 - (D1 - D0);

	lo = lo0 - (lo1 - lo0);
	la = la0 - (la1 - la0);

	//보정 작업
	if (D <= 0) {
		M--;
	}
	else if (D > 30) {
		M++;
	}
	if (M <= 0) {
		Y--;
	}
	else if (M > 12) {
		Y++;
	}


	if (M <= 0) {
		M += 12;
	}
	else if (M > 12) {
		M -= 12;
	}

	if (D <= 0) {
		D += 30;
	}
	else if (D > 30) {
		D -= 30;
	}

	//la, lo 예외 처리 X

	cout << Y << " " << M << " " << D << " ";
	cout << fixed;
	cout.precision(3);
	cout << lo << " " << la << "\n";

	return 0;
}