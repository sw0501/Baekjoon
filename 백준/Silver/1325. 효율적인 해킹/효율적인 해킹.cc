#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>


using namespace std;

int N, M;
vector<int>com[10001];
vector<pair<int, int>>answer;
int visit[10001] = { 0, };

int DFS(int idx) {
	visit[idx] = 1;
	int cnt = 0;
	for (int i = 0; i < com[idx].size(); i++) {
		if (visit[com[idx][i]] == 0) {
			cnt++;
			cnt += DFS(com[idx][i]);
		}
	}
	return cnt;
}

bool compare(const pair<int,int> &p1, const pair<int, int>& p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first > p2.first;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		com[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[j] = 0;
		}
		answer.push_back({ DFS(i) ,i});
	}

	sort(answer.begin(), answer.end(),compare);

	int cnt = answer[0].first;
	for(int i=0;i<N;i++){
		
		if (answer[i].first == cnt) {
			cout << answer[i].second << " ";
		}
		
	}

	return 0;
}