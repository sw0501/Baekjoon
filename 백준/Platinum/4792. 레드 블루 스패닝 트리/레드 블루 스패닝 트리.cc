#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge {
	int start, dest, cost;
};

int set[1001] = {0,};

//B의 개수가 
vector<Edge>vm;	//B 최소 mst
vector<Edge>vM;	//B 최대 mst


int getParent(int node) {
	if (node == set[node]) {
		return node;
	}
	else return set[node] = getParent(set[node]);
}

int find(int n1, int n2) {
	n1 = getParent(n1);
	n2 = getParent(n2);

	if (n1 == n2)return 1;
	else return 0;
}

void unionParent(int n1, int n2) {
	n1 = getParent(n1);
	n2 = getParent(n2);

	if (n1 > n2)set[n2] = n1;
	else set[n1] = n2;
}

bool operator < (Edge& a, Edge& b) {
	return a.cost < b.cost;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, f, t;
	char c;

	
	while (1) {
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0) {
			break;
		}

		for (int i = 1; i <= n; i++) {
			set[i] = i;
		}

		for (int i = 0; i < m; i++) {
			cin >> c >> f >> t;
			if (c == 'B') {
				vM.push_back({ f,t,0 });
				vm.push_back({ f,t,1 });
			}
			else {
				vM.push_back({ f,t,1 });
				vm.push_back({ f,t,0 });
			}
		}

		sort(vm.begin(), vm.end());
		sort(vM.begin(), vM.end());

		int cnt = 0;
		int cntBlueMin = 0;
		int cntBlueMax = 0;

		for (int i = 0; i < vm.size(); i++) {
			if (!find(vm[i].start, vm[i].dest)) {
				unionParent(vm[i].start, vm[i].dest);
				cnt++;
				if (vm[i].cost == 1)cntBlueMin++;
			}
			if (cnt == n - 1)break;
		}

		for (int i = 1; i <= n; i++) {
			set[i] = i;
		}
		cnt = 0;
		for (int i = 0; i < vM.size(); i++) {
			if (!find(vM[i].start, vM[i].dest)) {
				unionParent(vM[i].start, vM[i].dest);
				cnt++;
				if (vM[i].cost == 0)cntBlueMax++;
			}
			if (cnt == n - 1)break;
		}

		if (cntBlueMin <= k && k <= cntBlueMax) {
			cout << 1 << "\n";
		}
		else
			cout << 0 << "\n";

		vm.clear();
		vM.clear();
	}
    
	return 0;
}