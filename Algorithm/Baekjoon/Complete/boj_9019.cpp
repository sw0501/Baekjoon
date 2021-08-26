#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

int T;				//테스트케이스
void init();
void BFS(int a,int b);
int D(int x);
int S(int x);
int L(int x);
int R(int x);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	//최소횟수를 구하는 문제 : BFS
	cin >> T;
	int a,b;	//a:초기값 b:최종값
	for(int i=0;i<T;i++){
		cin >> a >> b;
		BFS(a,b);
	}
}

void BFS(int a,int b){
	int CK[10000]={0,};	//방문 기록
	queue<pair<int,string>>q;
	q.push(pair<int,string>(a,""));
	while(!q.empty()){
		
		//탐색할 노드 저장
		pair<int,string> node = q.front();
		int num = node.first;
		string str = node.second;
		
		//방문하지 않은 노드라면
		if(CK[num]==0){
			int temp;	//임시저장
			CK[num]=1;	//방문 기록
			
			
			//DSLR의 결과 확인 후 큐에 저장
			temp = D(num);
			if(CK[temp]!=1)q.push(pair<int,string>(temp,str+"D"));
			if(temp==b){
				cout << str+"D" << "\n";
				return ;
			}
			
			temp = S(num);
			if(CK[temp]!=1)q.push(pair<int,string>(temp,str+"S"));
			if(temp==b){
				cout << str+"S" << "\n";
				return ;
			}
			
			temp = L(num);
			if(CK[temp]!=1)q.push(pair<int,string>(temp,str+"L"));
			if(temp==b){
				cout << str+"L" << "\n";
				return ;
			}
			
			temp = R(num);
			if(CK[temp]!=1)q.push(pair<int,string>(temp,str+"R"));
			if(temp==b){
				cout << str+"R" << "\n";
				return ;
			}
		}
		q.pop();	//탐색이 끝난 노드 큐에서 제거
	}
}

int D(int x){
	
	if(2*x>9999)return (2*x)%10000;
	return 2*x;
}

int S(int x){
	if(x==0)return 9999;
	return x-1;
}

int L(int x){
	int n[4]={0,};
	for(int i=3;i>=0;i--){
		n[i] = x%10;
		x/=10;
	}
	
	int temp = n[0];
	
	n[0] = n[1];
	n[1] = n[2];
	n[2] = n[3];
	n[3] = temp;
	
	x=0;
	for(int i=0;i<4;i++){
		x*=10;
		x+=n[i];
	}
	return x;
}

int R(int x){
	int n[4]={0,};
	for(int i=3;i>=0;i--){
		n[i] = x%10;
		x/=10;
	}
	
	int temp = n[3];
	
	n[3] = n[2];
	n[2] = n[1];
	n[1] = n[0];
	n[0] = temp;
	
	x=0;
	for(int i=0;i<4;i++){
		x*=10;
		x+=n[i];
	}
	return x;
}

