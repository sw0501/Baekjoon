#include <bits/stdc++.h>

using namespace std;

//set
int parent[10001] = { 0, };

//우선순위
int c[3];

//집합 부모 찾기
int getParent(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = getParent(parent[x]);
}

//집합 연결 여부
int find(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b) {
		return 1;
	}
	else return 0;
}

//집합 합치기
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a > b) {
		parent[a] = b;
	}
	else
	{
		parent[b] = a;
	}
}

//간선
struct Edge {
	int u, v, w, k;
};

//PQ 비교 함수
struct compare {

	//연산자 오버로딩
	bool operator ()(Edge& e1, Edge& e2) {
		//설치 비용이 같은 경우 우선순위
		if (e1.w == e2.w) {
			return c[e1.k] > c[e2.k];
		}
		//설치비용 최소 순
		return e1.w > e2.w;
	}

};

//PQ
priority_queue<Edge, vector<Edge>, compare>pq;

//지역 개수
int N;
//경로 개수
int M;
//도로 종류별 개수
int cnt[3] = { 0, };
//도로 종류별 비용
int weight[3] = { 0, };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//지역과 도로 개수
	cin >> N >> M;

	//집합 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	int C[3];

	//우선순위
	for(int i=0;i<3;i++){
		cin >> C[i];
	}

	for(int i=0;i<3;i++){
		c[C[i]] = i;
	}

	//u : 정점 1
	//v : 정점 2
	//w : 도보 설치 비용
	//k : 도보 종류
	for (int i = 0; i < M; i++) {
		int u, v, w, k;

		cin >> u >> v >> w >> k;

		pq.push({ u,v,w,k });
	}



	int cost = 0;

	while (!pq.empty()) {

		int u, v, w, k;
		u = pq.top().u;
		v = pq.top().v;
		w = pq.top().w;
		k = pq.top().k;

		pq.pop();

		//이미 연결된 정점인 경우
		if (find(u, v)) {
			continue;
		}

		//연결 가능한 경우
		unionParent(u, v);

		//설치 비용 더해주기
		cost += w;

		//도로 설치 개수 증가
		cnt[k]++;

		//도로 설치 비용 
		weight[k] += w;
	}

	//총 비용 출력
	cout << cost << "\n";

	//도로 설치 개수 및 비용
	for(int i=0;i<3;i++){
		cout << cnt[i] << " " << weight[i] << "\n";
	}
	

	return 0;
}