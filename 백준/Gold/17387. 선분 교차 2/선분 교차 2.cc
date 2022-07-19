#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

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

int N;
int set[3001] = { 0, };
int SIZE[3001] = { 0, };
int MAX = 1;
int cnt = 1;

vector<Line>v;

int CCW(Point A,Point B, Point C) {
	__int128 tmp = A.x * B.y + B.x * C.y + C.x * A.y;
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
	
	int ans1 = CCW(l1.p1, l1.p2, l2.p1) * CCW(l1.p1, l1.p2, l2.p2);
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
		if (ans1 <= 0 && ans2 <= 0)return 1;
		else return 0;
	}
}

int getParent(int x) {
	if (x == set[x])return x;
	else return set[x] = getParent(set[x]);
}

void unionParent(Line a, Line b) {
	int i1, i2;
	i1 = getParent(a.i);
	i2 = getParent(b.i);
	if (i1 == i2) {
		return;
	}
	else if (i1 < i2) {
		cnt--;
		set[i2] = i1;
		SIZE[i1] += SIZE[i2];
		if (SIZE[i1] > MAX) {
			MAX = SIZE[i1];
		}
	}
	else {
		cnt--;
		set[i1] = i2;
		SIZE[i2] += SIZE[i1];
		if (SIZE[i2] > MAX) {
			MAX = SIZE[i2];
		}
	}
}

int find(Line a, Line b) {
	a.i = getParent(a.i);
	b.i = getParent(b.i);
	if (a.i == b.i)return 1;
	else return 0;
}



int main() {

	for (int i = 0; i < 2; i++) {
		set[i] = i;
		SIZE[i] = 1;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back(Line{ i,{x1,y1} ,{x2, y2} });
	}

	int temp = CK(v[0], v[1]);

	cout << temp << "\n";

	return 0;
}