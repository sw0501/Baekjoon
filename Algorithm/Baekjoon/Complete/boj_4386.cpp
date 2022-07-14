#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int N;
typedef struct edge {
	int start, dest;
	double cost;
}Edge;

typedef struct star {
	int num;
	double x, y;
}Star;

vector<Edge>v;
vector<Star> star;

int set[10001];


int getParent(int set[], int x) {
	if (set[x] == x)return x;
	return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);

	if (a < b)set[b] = a;
	else set[a] = b;
}

int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b)return 1;
	return 0;
}

bool operator <(Edge a, Edge b) {
	return a.cost < b.cost;
}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		double a, b;
		cin >> a >> b;
		star.push_back({ i,a,b });
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			else {
				double distance = sqrt((star[i].x - star[j].x) * (star[i].x - star[j].x) + (star[i].y - star[j].y) * (star[i].y - star[j].y));
				v.push_back({ i,j ,distance });
			}
		}
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i <= N; i++) {
		set[i] = i;
	}
	
	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(set, v[i].start, v[i].dest)) {
			sum += v[i].cost;
			unionParent(set, v[i].start, v[i].dest);
		}
	}

	cout << sum << "\n";
	

	return 0;
}