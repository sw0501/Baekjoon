#include<iostream>
#include<queue>

using namespace std;

int N; //정점 개수
int M; //간선 개수
int V; //시작 노드


int data[1000][1000]={0}; //노드 관계 저장
int visit_DFS[1000]={0}; //DFS 방문 기록

void print_DFS(int next); //DFS 출력 함수

int main(){
	
	cin >> N >> M >> V; //정점, 간선, 시작 노드 입력
		
	//데이터 입력
	//큰 수 작은 수 관계없이 입력
	for(int i=0;i<M;i++){
		int n,m;
		cin >> n >> m;
		data[n-1][m-1]=1;
		data[m-1][n-1]=1;
	}
	
	//함수 실행
	print_DFS(V); //V 노드를 첫 인수로 가져와서 V부터 시작
	
	
	return 0;
}

void print_DFS(int next){
	if(visit_DFS[next-1]==0) //방문안 한 노드일 경우에만 실행
	{ 
		visit_DFS[next-1]=1; //방문 기록 저장
		cout << next << " "; //노드 출력
		
		//노드와 연결된 다음 노드에 대해 print_DFS 함수 실행
		for(int i=0;i<N;i++)
		{			
			if(data[next-1][i]==1)
			{
				print_DFS(i+1);
			}
		}
	}
}
