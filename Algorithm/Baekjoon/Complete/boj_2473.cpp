#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int N;
int flood[100001] = { 0, };

int binary() {
	return 0;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> flood[i];
	}

	sort(flood, flood + N);

	int p1, p2, p3 = N;

	//양수만
	if (flood[0] >= 0) {
		cout << flood[0] << " " << flood[1] << " " << flood[2]  << "\n";
	}
	//음수만
	else if (flood[N-1] <= 0) {
		cout << flood[N - 3] << " " << flood[N - 2] << " " << flood[N-1] << "\n";
	}
	//양수 음수
	else {
		long long int temp = 300000000;
		int a=0, b=0, c=0;
		//p1 증가
		for (int i = 0; i < N - 2; i++) {
			p1 = i;
			p2 = i + 1;
			p3 = N-1;
			while (p2 < p3) {
				int value = flood[p1] + flood[p2] + flood[p3];
				if (abs(value) < temp) {
					temp = abs(value);
					a = flood[p1];
					b = flood[p2];
					c = flood[p3];
				}

				//총합이 음수인 경우 p2 증가
				if (value < 0) {
					p2++;
				}
				else if (value > 0) {
					p3--;
				}
				else {
					break;
				}
			}
		}

		cout << a << " " << b << " " << c << "\n";
	}
	return 0;
}