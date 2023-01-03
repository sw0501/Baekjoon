#include<iostream>
#include<queue>

using namespace std;

int N;
int M;
int V;

queue<int> BFS;

int data[1000][1000]={0};
int visit_DFS[1000]={0};
int visit_BFS[1000]={0};

void DFS(int next);

int main(){
	
	cin >> N >> M >> V;
	BFS.push(V);
	int bfs[1000];
	int count_d;
	int count_b;
	for(int i=0;i<M;i++){
		int n,m;
		cin >> n >> m;
		data[n-1][m-1]=1;
		data[m-1][n-1]=1;
	}
	/*for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(data[i][j]==1)cout<<i+1<<" "<<j+1<<endl;
		}
	}*/
	
	//DFS
	//V 노드부터 시작
	DFS(V);
	cout << endl;
	//시작점 push();
	//시작점 저장
	//이미 검색완료된 노드면 아래 과정 안한 후 팝
	//처음 검색한 노드는 팝해주고 연결된 노드들 푸쉬
	//마지막 노드일 경우에도 출력 후 팝
	//이후에 노드 출력
	//dfs 도 큐로 만들수있음
	//BFS
	
	while(!BFS.empty()){
		int node = BFS.front();
		/*
		int temp=1;
		for(int i=0;i<count_d;i++){
			if(node==bfs[i])temp=0;
		}
		*/
		if(visit_BFS[node-1]==0){
			visit_BFS[node-1]=1;
			for(int i=0;i<N;i++){
				if(data[node-1][i]==1){
					BFS.push(i+1);
				}
			}
			//bfs[count_d++] = node;
			cout << node << " ";
		}
		BFS.pop();
	}
	
	return 0;
}

//V노드부터 시작
//연결된 노드 찾기
//노드 찾았으면 그 노드의 다음 노드 찾기
//하면서 VISIT에 방문기록 저장
//마지막이면 탈출
//V노드의 다음노드가 방문한 노드이면 건너뜀

void DFS(int next){
	if(visit_DFS[next-1]==0){
		visit_DFS[next-1]=1;
		cout << next << " ";
		for(int i=0;i<N;i++){
			if(data[next-1][i]==1){
				DFS(i+1);
			}
		}
	}
}


