#include <bits/stdc++.h>

using namespace std;

void init();

int T;
priority_queue<long long,vector<long long>,greater<long long>>asc_Q;
priority_queue<long long>desc_Q;
map<long long, int>m;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> T;
	for(int t=0;t<T;t++){
		int K;
		cin >> K;
		for(int i=0;i<K;i++){
			string oper;
			long long num;
			
			cin >> oper >> num;
			//삽입 명령
			if(oper=="I"){
				asc_Q.push(num);
				desc_Q.push(num);
				m[num]++;
			}
			//삭제 명령
			else {
				//map이 비어있지 않다면
				if(!m.empty()){
					//최댓값 삭제 명령
					if(num==1){
						//map에 없는 원소들 삭제
						while(!desc_Q.empty()&&m[desc_Q.top()]==0){
							desc_Q.pop();
						}
						//최대값 삭제
						if(!desc_Q.empty()){
							//map에서 최대값 원소 삭제
							m[desc_Q.top()]--;
							//desc_Q 큐에서 원소 제거
							desc_Q.pop();
						}
					}
					//최솟값 삭제 명령
					else{
						//map에 없는 원소들 삭제
						while(!asc_Q.empty()&&m[asc_Q.top()]==0){
							asc_Q.pop();
						}
						//최대값 삭제
						if(!asc_Q.empty()){
							//map에서 최대값 원소 삭제
							m[asc_Q.top()]--;
							//asc_Q 큐에서 원소 제거
							asc_Q.pop();
						}
					}
				}
			}
		}
		
		//map에 없는 원소들 삭제
		while(!desc_Q.empty()&&m[desc_Q.top()]==0){
			desc_Q.pop();
		}
		
		//map에 없는 원소들 삭제
		while(!asc_Q.empty()&&m[asc_Q.top()]==0){
			asc_Q.pop();
		}
		
		//map이 비어있다면
		if(desc_Q.empty()||asc_Q.empty()){
			cout << "EMPTY\n";
		}
		else {
			
			cout << desc_Q.top() << " " << asc_Q.top() << "\n";
		}
		
		//큐 초기화
		asc_Q = priority_queue<long long,vector<long long>,greater<long long>>();
		
		desc_Q = priority_queue<long long>();
		
		m = map<long long, int>();
		
	}
}
