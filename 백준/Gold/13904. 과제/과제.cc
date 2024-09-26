#include<iostream>
#include<queue>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second < p2.second;
	}
};

int main() {

	priority_queue<pair<int, int>, vector<pair<int,int>>,cmp>PQ;

	int N;
	cin >> N;

	int date[1001] = { 0, };
	int score = 0;

	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;
		PQ.push(make_pair(d, w));
	}


	
	while (!PQ.empty()) {
		//cout << PQ.top().first << " " << PQ.top().second << "\n";
		for (int i = PQ.top().first; i >= 1; i--) {
			if (date[i] == 0) {
				date[i] = 1;
				score += PQ.top().second;
				break;
			}
		}
		PQ.pop();
	}

	cout << score << "\n";


	return 0;
}