#include <bits/stdc++.h>

using namespace std;

void init();

int N;
vector<int>seq;
int CK[100001] = {0,};
stack<int>st;
queue<char>answer;

int main(){
	
	/*
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	
	init();
	
	
	return 0;
}

void init(){
	int flag = 1;
	cin >> N;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		seq.push_back(num);
	}
	
	int idx = 0;	//수열의 인덱스 표시
	
	for(int i=1;i<=N;i++){
		st.push(i);
		answer.push('+');
		while(!st.empty()){
			//수열의 수일 경우 팝
			if(st.top()==seq[idx]){
				st.pop();
				answer.push('-');
				idx++;
			}
			else break;
		}
	}
	
	if(st.empty()){
		while(!answer.empty()){
			cout << answer.front() << "\n";
			answer.pop();
		}
	}
	else cout << "NO" << "\n";
}
