#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>Graph[32001];
int N, M;
int degree[32001]={0,};	//위상 정렬을 위한 차수 저장

bool compare(int a,int b) {
	return a > b;
}

//위상 정렬
void topology_sort() {
	priority_queue<int,vector<int>,greater<int>>Q;

	//차수가 0인 정점들 큐에 삽입
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			Q.push(i);
		}
	}

	//차수를 낮춰가면서 0인 정점들 큐에 삽입
	for (int i = 1; i <= N; i++) {
		if (Q.empty())continue;
		int x = Q.top();	//차수가 0인 정점
		Q.pop();	//간선이 모두 제거된 노드는 큐에서 팝
		cout << x << " ";

		//해당 노드에 연결된 간선 모두 제거후 차수가 0이된 정점은 Q에 삽입
		for (int j = 0; j < Graph[x].size(); j++) {
			if (--degree[Graph[x][j]] == 0) {
				Q.push(Graph[x][j]);
			}
		}
	}
}

int main() {

	cin >> N >> M;

	//a 가 b보다 앞에 있어야함
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);	//차수가 더 낮은 노드에 차수 높은 노드 저장
		degree[b]++;				//차수 증가
	}

	topology_sort();

	return 0;
}