#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char grid[21][21] = { 0, };

struct Point {
	long long int x, y;
};

struct Line {
	int i;
	Point p1, p2;
};

bool operator >= (Point a,Point b) {
	if (a.x == b.x) {
		return a.y >= b.y;
	}
	return a.x >= b.x;
}

vector<Line>v;

int CCW(Point A,Point B, Point C) {
	int tmp = A.x * B.y + B.x * C.y + C.x * A.y;
	tmp -= B.x * A.y + C.x * B.y + A.x * C.y;
	
	if (tmp > 0)return 1;
	else if (tmp == 0)return 0;
	else return -1;
}

void swap(Point &a, Point &b) {
	int tx = a.x;
	int ty = a.y;
	a.x = b.x;
	a.y = b.y;
	b.x = tx;
	b.y = ty;
}

int CK(Line l1, Line l2) {
	
	//ABC ABD
	int ans1 = CCW(l1.p1, l1.p2, l2.p1) * CCW(l1.p1, l1.p2, l2.p2);
	//CDA CDB
	int ans2 = CCW(l2.p1, l2.p2, l1.p1) * CCW(l2.p1, l2.p2, l1.p2);
	
	if (ans1 == 0 && ans2 == 0) {

		if (l1.p1 >= l1.p2) {
			swap(l1.p1, l1.p2);
		}
		if (l2.p1 >= l2.p2) {
			swap(l2.p1, l2.p2);
		}

		if (l2.p2 >= l1.p1 && l1.p2 >= l2.p1)return 1;
		return 0;
	}
	else{
		if (ans1 <= 0 && ans2 <= 0)return 2;
		else return 0;
	}
}

int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		Line l1;
		Line S[4];
		Point p1, p2, p3, p4;
		cin >> l1.p1.x >> l1.p1.y >> l1.p2.x >> l1.p2.y;
		
		

		if (l1.p1 >= l1.p2) {
			swap(l1.p1, l1.p2);
		}

		grid[l1.p1.y + 10][l1.p1.x + 10] = '1';
		grid[l1.p2.y + 10][l1.p2.x + 10] = '2';

		cin >> p1.x >> p1.y >> p2.x >> p2.y;

		if (p1.x>p2.x) {
			//1 3
			if (p1.y > p2.y) {
				p3.x = p2.x;
				p3.y = p1.y;
				p4.x = p1.x;
				p4.y = p2.y;

				if (l1.p1.x <= p1.x && l1.p1.x >= p2.x && l1.p2.x <= p1.x && l1.p2.x >= p2.x) {
					if (l1.p1.y <= p1.y && l1.p1.y >= p2.y && l1.p2.y <= p1.y && l1.p2.y >= p2.y) {
						cout << "T" << "\n";
						continue;
					}
				}

			}
			//4 2
			else {
				p3.x = p1.x;
				p3.y = p2.y;
				p4.x = p2.x;
				p4.y = p1.y;

				if (l1.p1.x <= p1.x && l1.p1.x >= p2.x && l1.p2.x <= p1.x && l1.p2.x >= p2.x) {
					if (l1.p1.y >= p1.y && l1.p1.y <= p2.y && l1.p2.y >= p1.y && l1.p2.y <= p2.y) {
						cout << "T" << "\n";
						continue;
					}
				}
			}
		}

		else {
			//2 4
			if (p1.y > p2.y) {
				p3.x = p2.x;
				p3.y = p1.y;
				p4.x = p1.x;
				p4.y = p2.y;

				if (l1.p1.x >= p1.x && l1.p1.x <= p2.x && l1.p2.x >= p1.x && l1.p2.x <= p2.x) {
					if (l1.p1.y <= p1.y && l1.p1.y >= p2.y && l1.p2.y <= p1.y && l1.p2.y >= p2.y) {
						cout << "T" << "\n";
						continue;
					}
				}
			}
			//3 1
			else {
				p3.x = p1.x;
				p3.y = p2.y;
				p4.x = p2.x;
				p4.y = p1.y;

				if (l1.p1.x >= p1.x && l1.p1.x <= p2.x && l1.p2.x >= p1.x && l1.p2.x <= p2.x) {
					if (l1.p1.y >= p1.y && l1.p1.y <= p2.y && l1.p2.y >= p1.y && l1.p2.y <= p2.y) {
						cout << "T" << "\n";
						continue;
					}
				}
			}

		}

		grid[p1.y + 10][p1.x + 10] = 'S';
		grid[p2.y + 10][p2.x + 10] = 'S';
		grid[p3.y + 10][p3.x + 10] = 'S';
		grid[p4.y + 10][p4.x + 10] = 'S';

		/*
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}
		*/

		//라인 만들어서 넣어주기
		S[0].p1 = p1;
		S[0].p2 = p3;

		S[1].p1 = p3;
		S[1].p2 = p2;

		S[2].p1 = p2;
		S[2].p2 = p4;

		S[3].p1 = p4;
		S[3].p2 = p1;

		int flag = 0;

		for (int i = 0; i < 4; i++) {
			if (CK(l1, S[i])) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << "T" << "\n";
		}
		else {
			cout << "F" << "\n";
		}
	}



	return 0;
}