#include<iostream>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

int main() {

	int N;

	vector<int>v[51];
	queue<int>Q;

	cin >> N;

	int root = -1;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x != -1) {
			v[x].push_back(i);
		}
		else root = i;
	}
    
	int D;
	cin >> D;

	
	int C = 0;
	
	Q.push(root);
	while (!Q.empty()) {
		//리프노드가 지워져서 해당 노드가 리프노드가 된 경우
		if (Q.front() != D) {
			if (v[Q.front()].size() == 0||(v[Q.front()].size()==1 &&v[Q.front()][0]==D))C++;
			else {
				for (int i = 0; i < v[Q.front()].size(); i++) {
					Q.push(v[Q.front()][i]);
				}
			}
		}
		Q.pop();
	}
	cout << C << "\n";

	return 0;
}