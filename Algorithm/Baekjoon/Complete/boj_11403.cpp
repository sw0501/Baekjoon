#include <bits/stdc++.h>

using namespace std;

void init();

int N;
vector<int>v[100];
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
		for(int j=0;j<N;j++){
			int temp;
			cin >> temp;
			if(temp){
				v[i].push_back(j);
			}
		}
	}
	
	for(int i=0;i<N;i++){
		int CK[100]={0,};
		queue<int>q;
		q.push(i);
		while(!q.empty()){
			int num = q.front();
			q.pop();
			for(int k=0;k<v[num].size();k++){
				if(CK[v[num][k]]==0){
					CK[v[num][k]]=1;
					q.push(v[num][k]);
				}
				
			}
		}
		for(int j=0;j<N;j++){
			cout << CK[j] << " ";
		}
		cout << "\n";
	}
}
