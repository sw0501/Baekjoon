#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

int F,S,G,U,D;
int CK[1000001]={0,};
queue<pair<int,int> > q;

void init();
void BFS();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> F >> S >> G >> U >> D;
	
	fill_n(CK,1000001,1000001);
	
	q.push(make_pair(S,0));
	BFS();
}

void BFS(){
	while(!q.empty()){
		int floor = q.front().first;
		int count = q.front().second;
		q.pop();
		
		//버튼을 누른 횟수를 비교하여 적을 경우 큐에 저장
		if(CK[floor]>count){
			CK[floor]=count;
			//목적지에 도착한 경우 큐에 저장하는 과정 건너뛰기
			if(floor==G)continue;
		}
		else {
			continue;
		}
		
		//이동할 수 있는 층인 경우
		if(floor+U<=F){
			q.push(make_pair(floor+U,count+1));
		}
		
		//이동할 수 있는 층인 경우
		if(floor-D>=1){
			q.push(make_pair(floor-D,count+1));
		}
	}
	if(CK[G]==1000001)cout << "use the stairs" << "\n";
	else cout << CK[G] << "\n";
	
}
