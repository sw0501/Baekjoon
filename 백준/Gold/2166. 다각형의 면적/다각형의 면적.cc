#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

struct pos {
	long double x;
	long double y;
};

int N;
vector<pos>points;

void init() {
	cin >> N;
	pos temp;
	for (int i = 0; i < N; i++) {
		cin >> temp.x >> temp.y;
		points.push_back(temp);
	}
}

long double crossProduct() {

	long double area = 0;

	//삼각형 외적 넓이 구하는 공식
	//(x1,y2 + x2,y3 + x3,y1 - x2,y1 - x3,y2 - x1,y3)/2
	
	//기준점, i, i+1 로 만들어지는 삼각형 넓이를 계산
	for (int i = 1; i < N-1; i++) {;
	area += (points[0].x * points[i].y + points[i].x * points[i+1].y + points[i + 1].x * points[0].y - points[i].x * points[0].y - points[i + 1].x * points[i].y - points[0].x * points[i + 1].y) / 2.0;
	}

	return area;
}

int main() {

	init();

	printf("%.1LF",abs(crossProduct()));

	return 0;
}