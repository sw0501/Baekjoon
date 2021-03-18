#include<iostream>
#include<vector>

using namespace std;

int N;
long long E=0;	//ㄷ 개수
long long W=0;	//ㅈ 개수
vector<vector<int> > tree;	//벡터 트리
int C[300001]={0,};	//정점 개수
int V[300001]={0,};	//방문 확인
void init();
void Search(int node, int c);	//node = 검색할 정점, c = 카운트
int Search1(int node, int c);	//node = 검색할 정점, c = 카운트
int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=0;i<=N;i++){
		vector<int>element;
		tree.push_back(element);
	}
	//연결된 정점 저장
	for(int i=0;i<N-1;i++){
		int x,y;
		cin >> x >> y;
		
		//연결된 정점 개수 갱신
		C[x]++;
		C[y]++;
		
		//연결된 정점 저장
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	//ㅈ 트리 탐색
	for(int i=1;i<=N;i++){
		//연결된 정점이 3개이상 이라면 nCm을 이용하여 계산
		if(C[i]>=3){
			long long temp=1;
			for(int j=C[i];j>=C[i]-2;j--)temp*=j;
			W+=temp/6;
		}
		Search(i,1);
	}
		
	//cout << E << W << endl;
	E = E/2;
	if(E>3*W)cout << "D";
	else if(E==3*W)cout << "DUDUDUNGA";
	else cout << "G";
	
}

//굳이 재귀함수 안돌려도 풀 수 있음 근데 재귀로 풀어야 맞는거 아닌가 DP인데
void Search(int node, int c){
	//연결된 정점 방문
	for(int i=0;i<tree[node].size();i++){
		E+=(C[node]-1)*(C[tree[node][i]]-1);
	}
}

int Search1(int node, int c){
	//연결된 정점이 3개 이상이라면
	if(C[node]>=2){
		
	}
}
