#include <bits/stdc++.h>

using namespace std;

void init();
struct cmp{
	bool operator()(int n1,int n2){
		if(abs(n1)>abs(n2)){
			return true;
		}
		else if(abs(n1)==abs(n2)){
			if(n1>n2)return true;
			return false;
		}
		return false;
	}
};

priority_queue<int,vector<int>,cmp>Q;
int N;


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=0;i<N;i++){
		int input;
		cin >> input;
		if(input==0){
			//배열이 비어있을 때 출력 명령이 들어온 경우
			if(Q.empty())cout << "0\n";
			else {
				cout << Q.top() << "\n";
				Q.pop();
			}
		}
		else{
			Q.push(input);
		}
	}
}
