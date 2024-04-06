#include<iostream>
#include<unordered_map>
#include<queue>
#include<unordered_set>
#include<set>

using namespace std;

string map[5];

struct star {
	int x, y, num;
};

vector<star> v;
int len = 0;
int visit[26] = { 0, };

int line[7] = { 0, };

vector<int> point[12];

bool check() {

	for (int i = 1; i < 7; i++) {
		if (line[i] != 26)return false;
	}

	return true;
}


bool DFS(int idx) {
	//cout << idx << "\n";
	if (idx == len) {
		if (check()) {
			return true;
		}
		return false;
	}

	for (int i = 0; i <= (int)('L'-'A'); i++) {
		if (visit[i])continue;
		visit[i] = 1;
		map[v[idx].x][v[idx].y] = (char)('A' + i);
		
		line[point[v[idx].num][0]] += (i + 1);
		if (line[point[v[idx].num][0]] > 26) {
			line[point[v[idx].num][0]] -= (i + 1);
			visit[i] = false;
			continue;
		}

		line[point[v[idx].num][1]] += (i + 1);
		if (line[point[v[idx].num][1]] > 26) {
			line[point[v[idx].num][0]] -= (i + 1);
			line[point[v[idx].num][1]] -= (i + 1);
			visit[i] = false;
			continue;
		}

		if (DFS(idx + 1)) {
			return true;
		}

		line[point[v[idx].num][0]] -= (i + 1);
		line[point[v[idx].num][1]] -= (i + 1);

		visit[i] = 0;
	}

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		cin >> map[i];
	}

	point[0].push_back(1);
	point[0].push_back(2);

	point[1].push_back(3);
	point[1].push_back(5);

	point[2].push_back(1);
	point[2].push_back(5);

	point[3].push_back(2);
	point[3].push_back(5);

	point[4].push_back(4);
	point[4].push_back(5);

	point[5].push_back(1);
	point[5].push_back(3);

	point[6].push_back(2);
	point[6].push_back(4);

	point[7].push_back(1);
	point[7].push_back(6);

	point[8].push_back(3);
	point[8].push_back(6);

	point[9].push_back(4);
	point[9].push_back(6);

	point[10].push_back(2);
	point[10].push_back(6);

	point[11].push_back(3);
	point[11].push_back(4);

	int strLen = map[0].length();
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < strLen; j++) {
			if (map[i][j] == 'x') {
				v.push_back({i,j,cnt});
				cnt++;
			}
			else if (map[i][j] >= 'A' && map[i][j] <= 'Z') {
				visit[map[i][j] - 'A'] = 1;
				line[point[cnt][0]] += (int)(map[i][j] - 'A' + 1);
				line[point[cnt][1]] += (int)(map[i][j] - 'A' + 1);
				cnt++;
			}
		}
	}

	len = v.size();

	DFS(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < strLen; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}

	return 0;
}