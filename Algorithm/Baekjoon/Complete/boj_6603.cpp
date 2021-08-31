#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

int k;			//원소의 개수
int p[6]={0,};	//출력 원소 집합

void init();

void DFS(vector<int>s,int C,int idx);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	while(1){
		vector<int>s;	//입력 원소 집합
		cin >> k;
		if(k==0)break;
		for(int i=0;i<k;i++){
			int n;
			cin >> n;
			s.push_back(n);
		}
		DFS(s,0,0);
		cout << "\n";
	}
}

void DFS(vector<int>s,int C,int idx){
	for(int i = idx;i<s.size();i++){
		p[C] = s[i];
		if(C==5){
			for(int j=0;j<6;j++){
				cout << p[j] << " ";
			}
			cout << "\n";
		}
		else{
			DFS(s,C+1,i+1);
		}
	}
}