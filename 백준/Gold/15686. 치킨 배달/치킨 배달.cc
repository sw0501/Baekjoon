#include<iostream>
#include<vector>

using namespace std;

int city[50][50];
vector<pair<int, int>>h;
vector<pair<int, int>>ch;
vector<pair<int, int>>s;

int min_dist = 5000;
int N, M;

void select(int n, int m);

int main() {

	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) {
				h.push_back(make_pair(i, j));
			}
			else if (city[i][j] == 2) {
				ch.push_back(make_pair(i, j));
			}
		}
	}

	select(0, 1);

	cout << min_dist << "\n";

	return 0;
}

void select(int n,int m) {
	//치킨집 선택
	for (int i = n; i < ch.size(); i++) {
		//치킨집 고르기
		s.push_back(make_pair(ch[i].first, ch[i].second));
		//M개 치킨집 고른 경우 치킨 거리 최소값 계산
		if (m == M) {
			int total_dist = 0;
			for (int j = 0; j < h.size(); j++) {
				int dist = 10000;
				for (int k = 0; k < s.size(); k++) {
					int temp_dist 
						= (h[j].first - s[k].first > 0 ? h[j].first - s[k].first : -(h[j].first - s[k].first))
						+ (h[j].second - s[k].second > 0 ? h[j].second - s[k].second : -(h[j].second - s[k].second));
					dist = (dist > temp_dist ? temp_dist : dist);
				}
				total_dist += dist;
			}
			min_dist = (min_dist > total_dist ? total_dist : min_dist);
		}
		//M개 치킨집 고를때까지 반복
		else {
			select(i + 1, m + 1);
		}
		s.pop_back();
	}
}