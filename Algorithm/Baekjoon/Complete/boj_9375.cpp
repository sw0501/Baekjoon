#include <bits/stdc++.h>

using namespace std;

void init();

map<string,int>m;	//해당 요소의 개수만 중요하다.
int T,N;

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
		cin >> N;
		for(int i=0;i<N;i++){
			string name,specify;
			cin >> name >> specify;
			//해당하는 요소가 없다면
			if(m.find(specify)==m.end()){
				m[specify]++;
			}
			else m.find(specify)->second++;
		}
		
		int answer = 1;
		for(auto iter = m.begin();iter != m.end();++iter){
			answer *= iter->second+1;
		}
		cout << answer-1 << "\n";
		
		m = map<string,int>();
	}
	
}