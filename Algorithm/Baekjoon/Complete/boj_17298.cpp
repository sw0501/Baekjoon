#include <bits/stdc++.h>

using namespace std;

void init();

int v[1000001];
stack<pair<int,int>>st;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	
	fill(v,v+1000001,-1);
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		//오큰수인지 확인
		if(!st.empty()){
			//오큰수인경우 작은 수 가 나올때까지 팝 해주면서 v에 저장 
			while(num>st.top().first){
				v[st.top().second] = num;
				st.pop();
				if(st.empty())break;
			}
		}
		st.push(make_pair(num,i));
	}
	
	//스택에 남아있는 수들은 오큰수가 없기때문에 -1로 출력
	
	for(int i=0;i<N;i++){
		cout << v[i] << " ";
	}
	cout << "\n";
}