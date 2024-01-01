#include<iostream>
#include<algorithm>

using namespace std;

int h[1000] = { 0, };
int s[1000] = { 0, };
int d[1000] = { 0, };

int main(int argc, char** argv)
{
	int B, C, D;
	cin >> B >> C >> D;

	int price = 0;
	for (int i = 0; i < B; i++) {
		cin >> h[i];
		price += h[i];
	}

	for (int i = 0; i < C; i++) {
		cin >> s[i];
		price += s[i];
	}

	for (int i = 0; i < D; i++) {
		cin >> d[i];
		price += d[i];
	}

	//세트 메뉴는 햄버거 1개, 사이드 1개, 드링크 1개
	//비싼 순으로 정렬 후 앞에 꺼 하나 씩 고르기

	sort(h, h + B);
	reverse(h, h + B);
	sort(s, s + C);
	reverse(s, s + C);
	sort(d, d + D);
	reverse(d, d + D);

	int i=0, j=0, k=0;

	int ans = 0;
	while (i < B && j < C && k < D) {
		ans += (int)((h[i++] + s[j++] + d[k++]) * 0.9);
	}

	while (i < B) {
		ans += h[i++];
	}
	while (j < C) {
		ans += s[j++];
	}
	while (k < D) {
		ans += d[k++];
	}

	cout << price << "\n";
	cout << ans << "\n";

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}