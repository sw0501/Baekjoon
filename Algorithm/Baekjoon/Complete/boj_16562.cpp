#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N;
int M;
int K;
int P[10002]={0,};	//친구비
int H[10002]={0,};	//부모 노드 저장
int V[10002]={0,};	//방문 확인

void init();
int find(int x);
void Union(int x,int y);

int main(){
	
	init();
	
	return 0;
}

//시간복잡도 O(N)
void init(){
	cin >> N >> M >> K;
	for(int i=1;i<=N;i++){
		cin >> P[i];
		H[i] = i;
	}
	//입력을 받을 때 마다 루트인지 확인
	for(int i=1;i<=M;i++){
		int x,y;
		cin >> x >> y;
		Union(x,y);
	}
	long long friend_price=0;
	
	//M[]에 부모노드들이 저장되어있는데 중복방문하게 되면 비용이 늘어나게 되므로 이미 계산한 비용은 0으로 하면 중복 해결
	//H[i]에는 최종 부모가 들어있는 것이 아니므로 최종 부모를 찾아야한다.
	for(int i=0;i<=N;i++){
		int parent = find(H[i]);
		if(V[parent]!=1){
			friend_price+=P[parent];
			V[parent]=1;
		}
	}
	
	if(friend_price<=K)cout << friend_price << "\n";
	else cout << "Oh no" << "\n";
}

//Find에서는 부모노드 찾는 기능만
int find(int x){
	//부모노드라면 부모값 리턴
	if(x==H[x]){
		return x;
	}
	//아니라면 부모값을 찾아서 재귀, 저장 후 리턴
	else {
		int y = find(H[x]);	//부모값
		return y;
	}
}

//Union에서는 비용 비교하여 더 적은 것은 부모노드로 설정
void Union(int x,int y){
	//x의 부모노드
	x = find(x);
	//y의 부모노드
	y = find(y);		 
	//부모노드가 다르다면 비용이 더 적은 것을 부모노드로 지정
	if(x!=y){
		if(P[x]<P[y])H[y]=x;
		else H[x]=y;
	}
	//부모노드가 같다면 이 경우는 이미 비교가 완료된 경우이기 때문에 고려X
}