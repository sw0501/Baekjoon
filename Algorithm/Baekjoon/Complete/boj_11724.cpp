#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int M;
int L=0;

int CK[1001]={0,};		//방문 확인용 
vector<int>list[1001];	//관계 저장

void init();
void DFS(int node,int Depth);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int u,v;
		cin >> u >> v;
		//방향이 없는 그래프이기 때문에 양쪽 모두 저장해준다.
		list[u].push_back(v);
		list[v].push_back(u);
	}
	
	DFS(1,1);
	
	cout << L << "\n";
	
}

//방문안한 노드를 계속 찾아가면서 검색하고 연결요소 검색이 끝났으면 count 해준다.
void DFS(int node,int Depth){
	if(!CK[node]){
		CK[node]=1;
		for(int i=0;i<list[node].size();i++){
			 DFS(list[node][i],Depth+1);
		}
		if(Depth==1)L++;
	}
	
	//노드 탐색이 끝났고 정점을 모두 탐색한 것이 아니라면 다음 정점 탐색
	if(Depth==1&&node<N)
		DFS(node+1,Depth);
}

