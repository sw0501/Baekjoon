#include<iostream>

using namespace std;

int X, L, R, N;
long long ans1 = 0, ans2 = 0, ans3 = 0;
long long dp[4][21][4] = { 0, };	//[처음 수][N번 반복][1,2,3 개수]


long long pow(int x, int y) {
	//0인 경우 범위 = 1
	if (y == 0) {
		return 1;
	}
	else if (y == 1) {
		return x;
	}
	if (y & 1) {
		return pow(x, y - 1) * pow(x, 1);
	}
	else {
		return pow(x, y / 2) * pow(x, y / 2);
	}
}

int sqrt(long long  range) {
	int cnt = 0;
	for (range; range != 1; range /= 3, cnt++);

	return cnt;
}

void divide(int num, long long  range, long long left, long long  right) {
	//계산 범위 밖으로 벗어나는 경우
	if (range != 1 && (R < left || right < L)) {
		return;
	}
	//탐색 범위 내부에 있는 경우 DP 이용
	if (range != 1 && (L <= left && right <= R)) {
		int  r = sqrt(range);
		ans1 += dp[num][r][1];
		ans2 += dp[num][r][2];
		ans3 += dp[num][r][3];
		return;
	}

	//범위가 1인 경우 LEFT가 탐색범위 내에 있는 경우
	if (range == 1) {
		if (L <= left && left <= R) {
			if (num == 1) {
				ans1++;
			}
			else if (num == 2) {
				ans2++;
			}
			else {
				ans3++;
			}
		}
		return;
	}

	//재귀

	long long new_range = range / 3;
	long long f1 = left, s1 = f1 + new_range - 1;	//1번째 수
	long long f2 = s1 + 1, s2 = f2 + new_range - 1;	//2번째 수
	long long f3 = s2 + 1, s3 = f3 + new_range - 1;	//3번째 수

	if (num == 1) {
		divide(1, new_range, f1, s1);
		divide(3, new_range, f2, s2);
		divide(2, new_range, f3, s3);
	}
	else if (num == 2) {
		divide(2, new_range, f1, s1);
		divide(1, new_range, f2, s2);
		divide(1, new_range, f3, s3);
	}
	else if (num == 3) {
		divide(2, new_range, f1, s1);
		divide(3, new_range, f2, s2);
		divide(2, new_range, f3, s3);
	}
	return;
}


void cal() {

	//a = a + 2b
	//b = a + b + 2c
	//c = a + c

	//시작 수 1인경우
	int a = 1, b = 0, c = 0;
	int na, nb, nc;
	for (int n = 1; n <= 20; n++) {
		na = a + 2 * b;
		nb = a + b + 2 * c;
		nc = a + c;
		a = na; b = nb; c = nc;
		dp[1][n][1] = a;
		dp[1][n][2] = b;
		dp[1][n][3] = c;
	}

	//시작 수 2인 경우
	a = 0, b = 1, c = 0;
	for (int n = 1; n <= 20; n++) {
		na = a + 2 * b;
		nb = a + b + 2 * c;
		nc = a + c;
		a = na; b = nb; c = nc;
		dp[2][n][1] = a;
		dp[2][n][2] = b;
		dp[2][n][3] = c;
	}

	//시작 수 3인 경우
	a = 0, b = 0, c = 1;
	for (int n = 1; n <= 20; n++) {
		na = a + 2 * b;
		nb = a + b + 2 * c;
		nc = a + c;
		a = na; b = nb; c = nc;
		dp[3][n][1] = a;
		dp[3][n][2] = b;
		dp[3][n][3] = c;
	}
}

int main() {

	cin >> X >> L >> R >> N;

	cal();

	divide(X, pow(3, N), 0, pow(3, N) - 1);

	cout << ans1 << " " << ans2 << " " << ans3 << "\n";

	return 0;
}