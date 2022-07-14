#include<iostream>

using namespace std;

int N;
int flood[100001] = { 0, };

int binary() {
	return 0;
}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> flood[i];
	}

	int p1=1, p2=N;

	//양수만
	if (flood[1] >= 0) {
		cout << flood[1] << " " << flood[2] << "\n";
	}
	//음수만
	else if (flood[N]<=0) {
		cout << flood[N - 1] << " " << flood[N] << "\n";
	}
	//양수 음수
	else {
		int a = flood[p1], b = flood[p2];
		int value = flood[p1]+flood[p2];
		value = (value > 0 ? value : -value);

		//투포인터로 탐색
		while (p1 < p2) {
			int abs = flood[p1] + flood[p2];
			abs = (abs > 0 ? abs : -abs);
			//특성값이 0에 가깝다면
			if (abs <= value) {
				value = abs;
				a = flood[p1];
				b = flood[p2];
			}

			if (flood[p1] + flood[p2] < 0) {
				p1++;
			}

			else if(flood[p1]+flood[p2]>0) {
				p2--;
			}
			else {
				a = flood[p1];
				b = flood[p2];
				break;
			}
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}