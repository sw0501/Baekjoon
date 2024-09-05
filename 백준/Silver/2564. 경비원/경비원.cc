#include<bits/stdc++.h>

using namespace std;

struct Market{
	int p, d;
};

vector<Market>market;

int w, h;
int n;

int p, d;


int calc(int a,int b) {
	if (d == b) {
		return abs(p - a);
	}

	else {
		int c = 0;
		int nc = 0;
		switch (d) {
			case 1:
				switch (b) {
					//북북
					case 1:
						return abs(p - a);
						break;
					//북남
					case 2:
						c = w - p + h + w - a;
						nc = p + h + a;
						return min(c,nc);
						break;
					//북서
					case 3:
						nc = p + a;
						return nc;
						break;
					//북동
					case 4:
						c = w - p + a;
						return c;
						break;
				}
				break;
			case 2:
				switch (b) {
					//남북
					case 1:
						c = p + h + a;
						nc = w - p + h + w - a;
						return min(c, nc);
						break;
					//남남
					case 2:
						return abs(p - a);
						break;
					//남서
					case 3:
						nc = p + h - a;
						return nc;
						break;
					//남동
					case 4:
						nc = w - p +  h - a;
						return nc;
						break;
				}
			case 3:
				switch (b) {
					//서북
					case 1:
						c = p + a;
						return c;
						break;
					//서남
					case 2:
						nc = h - p + a;
						return nc;
						break;
					//서서
					case 3:
						return abs(p - a);
						break;
					//서동
					case 4:
						c = p + w + a;
						nc = h - p + w + h - a; 
						return min(c, nc);
						break;
				}
				break;
			case 4:
				switch (b) {
					//동북
					case 1:
						nc = p + w - a;
						return nc;
						break;
					//동남
					case 2:
						c = h - p + w - a;
						return c;
						break;
					//동서
					case 3:
						c = h - p + w + h - a;
						nc = p + w + a;
						return min(c, nc);
						break;
					//동동
					case 4:
						return abs(p - a);
						break;
				}
				break;
		}
	}
}

int main() {

	cin >> w >> h;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		market.push_back({ b,a });
	}
	
	cin >> d >> p;

	int dist = 0;

	for (int i = 0; i < n; i++) {
		int a = market[i].p;
		int b = market[i].d;
		
		int num = calc(a, b);
		dist += num;

	}

	cout << dist << "\n";

	return 0;
}