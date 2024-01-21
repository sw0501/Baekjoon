#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge {
	int start, dest, cost;
};

char univ[1001] = { 0, };
int set[1001] = {0,};

//B의 개수가 
vector<Edge>vm;
vector<Edge>vM;


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

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		set[i] = i;
	}

	int cnt = 0;
	int maxCost = 0;
	int minCost = 0;

	int start, dest, cost;
	cin >> start >> dest >> cost;

	//입구가 오르막인 경우
	if (cost == 0) {
		maxCost++;
		minCost++;
	}

	for (int i = 1; i <= M; i++) {
		cin >> start >> dest >> cost;

		//오르막길인 경우
		if (cost == 0) {
			vm.push_back({ start,dest,1 });
			vM.push_back({ start,dest,0 });
		}
		//내리막길인 경우
		else {
			vm.push_back({ start,dest,0 });
			vM.push_back({ start,dest,1 });
		}
	}

	sort(vm.begin(), vm.end());
	sort(vM.begin(), vM.end());

	
	for (int i = 0; i < vM.size(); i++) {
		if (!find(vM[i].start, vM[i].dest)) {
			cnt++;
			if(vM[i].cost==0)maxCost++;
			unionParent(vM[i].start, vM[i].dest);
		}
		if (cnt == N - 1)break;
	}

	maxCost = maxCost * maxCost;

	for (int i = 1; i <= N; i++) {
		set[i] = i;
	}

	cnt = 0;
	
	for (int i = 0; i < vm.size(); i++) {
		if (!find(vm[i].start, vm[i].dest)) {
			cnt++;
			if(vm[i].cost==1)minCost++;
			unionParent(vm[i].start, vm[i].dest);
		}
		if (cnt == N - 1)break;
	}
	minCost = minCost * minCost;
	cout << maxCost - minCost << "\n";

	return 0;
}
