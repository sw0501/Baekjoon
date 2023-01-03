#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>Graph[32001];
int N, M;
int degree[32001]={0,};	//위상 정렬을 위한 차수 저장
int result[1001]={0,};	//가수 순서 저장

//위상 정렬
int topology_sort() {
	queue<int>Q;

	//차수가 0인 정점들 큐에 삽입
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			Q.push(i);
		}
	}

	//차수를 낮춰가면서 0인 정점들 큐에 삽입
	for (int i = 1; i <= N; i++) {
		if (Q.empty()) {
			cout << 0 << "\n";
			return 0;
		}

		int x = Q.front();	//차수가 0인 정점
		Q.pop();			//간선이 모두 제거된 노드는 큐에서 팝
		result[i] = x;		//가수 순서 result에 저장

		//해당 노드에 연결된 간선 모두 제거후 차수가 0이된 정점은 Q에 삽입
		for (int j = 0; j < Graph[x].size(); j++) {
			if (--degree[Graph[x][j]] == 0) {
				Q.push(Graph[x][j]);
			}
		}
	}

	return 1;
}

int main() {

	cin >> N >> M;

	//a 가 b보다 앞에 있어야함
	for (int i = 0; i < M; i++) {
		int num,a,b;
		cin >> num;
		cin >> a;
		for (int n = 0; n < num-1; n++) {
			cin >> b;
			Graph[a].push_back(b);	//차수가 더 낮은 노드에 차수 높은 노드 저장
			degree[b]++;				//차수 증가
			a = b;
		}
	}

	if (topology_sort()) {
		for (int i = 1; i <= N; i++) {
			cout << result[i] << "\n";
		}
	}

	

	return 0;
}