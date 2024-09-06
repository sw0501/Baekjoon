#include<bits/stdc++.h>

using namespace std;

int N;

struct Dice{
	//해당 주사위 면이 아래쪽일 때 가장 높은 수 저장
	int value[7];
	int rev[7];
};

vector<Dice>dice;

//완탐
int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;

		int MA = max(b, max(c, max(d, e)));
		int MB = max(a, max(c, max(e, f)));
		int MC = max(a, max(b, max(d, f)));
		int MD = max(a, max(c, max(e, f)));
		int ME = max(a, max(b, max(d, f)));
		int MF = max(b, max(c, max(d, e)));


		//배열 저장
		int value[7] = { 0, };

		value[0] = 0;
		value[a] = MA;
		value[b] = MB;
		value[c] = MC;
		value[d] = MD;
		value[e] = ME;
		value[f] = MF;

		//반대편 눈금 저장
		int rev[7] = { 0, };

		rev[0] = 0;
		rev[a] = f;
		rev[b] = d;
		rev[c] = e;
		rev[d] = b;
		rev[e] = c;
		rev[f] = a;

		Dice temp = { 
			{value[0],value[1],value[2],value[3],value[4],value[5],value[6]}, 
			{rev[0],rev[1],rev[2],rev[3],rev[4],rev[5],rev[6]} 
		};

		dice.push_back({ temp });
	}
	

	int answer = 0;

	//주사위 1번의 눈 변경
	for (int i = 1; i <= 6; i++) {

		//배치해야할 주사위 눈 저장
		int num = i;
		int cnt = 0;

		int value = 0;

		while (cnt < N) {
			//주사위 눈금 저장
			value += dice[cnt].value[num];

			//반대편 눈금 저장
			num = dice[cnt].rev[num];

			cnt++;
		}

		answer = max(answer, value);
	}

	cout << answer << "\n";

	return 0;
}