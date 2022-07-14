#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct graph {
	int a;
	int b;
	int value;
}Graph;

int N, M;
int s[100001] = { 0, };
vector<Graph>v;

bool compare(Graph a,Graph b) {
	return a.value < b.value;
}

int getParent(int set[],int x) {
	if (set[x] == x)return x;
	return set[x] = getParent(set,set[x]);
}

void unionParent(int set[], int a,int b) {
	a = getParent(set,a);
	b = getParent(set,b);

	if (a < b)set[b] = a;
	else set[a] = b;
}

int find(int set[], int a,int b) {
	a = getParent(set,a);
	b = getParent(set,b);
	if (a == b) {
		return 1;
	}
	return 0;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		s[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	sort(v.begin(), v.end(), compare);

	long long int sum = 0;
	int temp;
	for (int i = 0; i < v.size(); i++) {
		if (!find(s,v[i].a, v[i].b)) {
			unionParent(s,v[i].a, v[i].b);
			sum += v[i].value;
			temp = v[i].value;
		}
	}

	cout << sum-temp << "\n";

	return 0;
}