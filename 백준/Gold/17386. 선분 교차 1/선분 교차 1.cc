#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Point {
	int i;
	long long int x1, y1, x2, y2;
};

vector<Point>v;

int CCW(Point p1, Point p2) {
	//CCW(ABC)
	__int128 f1 = (p1.x1 * p1.y2 + p1.x2 * p2.y1 + p2.x1 * p1.y1 - (p1.x2 * p1.y1 + p2.x1 * p1.y2 + p1.x1 * p2.y1));
	//CCW(ABD)
	__int128 f2 = (p1.x1 * p1.y2 + p1.x2 * p2.y2 + p2.x2 * p1.y1 - (p1.x2 * p1.y1 + p2.x2 * p1.y2 + p1.x1 * p2.y2));
	//CCW(CDA)
	__int128 s1 = (p2.x1 * p2.y2 + p2.x2 * p1.y1 + p1.x1 * p2.y1 - (p2.x2 * p2.y1 + p1.x1 * p2.y2 + p2.x1 * p1.y1));
	//CCW(CDB)
	__int128 s2 = (p2.x1 * p2.y2 + p2.x2 * p1.y2 + p1.x2 * p2.y1 - (p2.x2 * p2.y1 + p1.x2 * p2.y2 + p2.x1 * p1.y2));

	if (f1 * f2 <= 0 && s1 * s2 <= 0) {
		/*
		if (f1 * f2 == 0 && s1 * s2 == 0) {
			if (p1.x1 >= p1.x2) {
				if (p1.x1 == p1.x2) {
					if (p1.y1 >= p1.y2) {
						long long int tx = p1.x1, ty = p1.y1;
						p1.x1 = p1.x2;
						p1.y1 = p1.y2;
						p1.x2 = tx;
						p1.y2 = ty;
					}
				}
				else {
					long long int tx = p1.x1, ty = p1.y1;
					p1.x1 = p1.x2;
					p1.y1 = p1.y2;
					p1.x2 = tx;
					p1.y2 = ty;
				}
			}
			if (p2.x1 >= p2.x2) {
				if (p2.x1 == p2.x2) {
					if (p2.y1 >= p2.y2) {
						long long int tx = p2.x1, ty = p2.y1;
						p2.x1 = p2.x2;
						p2.y1 = p2.y2;
						p2.x2 = tx;
						p2.y2 = ty;
					}
				}
				else {
					long long int tx = p2.x1, ty = p2.y1;
					p2.x1 = p2.x2;
					p2.y1 = p2.y2;
					p2.x2 = tx;
					p2.y2 = ty;
				}
			}
			if (p1.x1 <= p2.x2 && p1.y1 <= p2.y2 && p2.x1 <= p1.x2 && p2.y1 <= p1.y2)return 1;
			return 0;
		}
		*/
		return 1;
	}
	return 0;
}

int main() {

	long long int x1, y1, x2, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	v.push_back({ 1, x1, y1, x2, y2 });
	cin >> x1 >> y1 >> x2 >> y2;
	v.push_back({ 2, x1, y1, x2, y2 });

	cout << CCW(v[0], v[1]) << "\n";

	return 0;
}