#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N;
int K;
vector<pair<long long ,long long > >jewel;	//보석 정보
vector<long long>bag;						//가방 정보
priority_queue<long long> pq;				//우선순위 큐

void init();
bool compare(pair<long long,long long>a,pair<long long,long long>b);


int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		long long w,v;
		cin >> w >> v;
		jewel.push_back(pair<long long,long long>(w,v));
	}
	for(int i=0;i<K;i++){
		long long w;
		cin >> w;
		bag.push_back(w);
	}
	//가방과 보석 오름차순으로 정렬해줘야됨
	sort(jewel.begin(),jewel.end(),compare);
	sort(bag.begin(),bag.end());
	
	//
	/*
	for(int i=0;i<N;i++){
		cout << jewel[i].first << " " << jewel[i].second << "\n";
	}
	for(int i=0;i<N;i++){
		cout << bag[i] << "\n";
	}
	*/
	
	//보석이 들어갈 수 있는지 파악 후 들어간다면 가치 저장 후 지워준다
	long long Value = 0;
	long long idx = 0;	//저장한 보석 인덱스
	for(int i=0;i<K;i++){
		while(idx<N){
			//가방에 들어간다면 저장
			if(bag[i]>=jewel[idx].first){
				pq.push(jewel[idx].second);
				idx++;
			}
			//더이상 들어가지 않는다면 탈출
			else break;
		}
		//같은 무게의 가방이 2개 들어와서 PQ에 들어있는 보석이 없는 경우도 고려
		//지금까지 우선수위 큐에 들어간 보석 중 가장 가치가 높은 것이 top에 저장되어있으므로 저장 후 팝해서 없애기
		if(!pq.empty()){
			Value += pq.top();
			pq.pop();
		}
		//현재 가방엔 못 넣지만 가방과 보석이 남아있는 경우 건너뜀
		else if(pq.empty()&&i<K&&idx<N)continue;
		//그 외의 경우 탈출
		else break;
	}
	
	cout << Value << "\n";
}

bool compare(pair<long long,long long>a,pair<long long,long long>b){
	return a.first<b.first;
}

