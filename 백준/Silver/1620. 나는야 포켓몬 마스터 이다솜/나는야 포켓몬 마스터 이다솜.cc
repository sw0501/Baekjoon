#include <bits/stdc++.h>

using namespace std;

void init();

map<string,int>m;
string dictionary[100001];
int N,M;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		string name;
		cin >> name;
		m.insert({name,i});
		dictionary[i] = name;
	}
	
	
	for(int i=0;i<M;i++){
		string question;
		cin >> question;
		
		//숫자인 경우 변환
		if(question[0]>='0'&&question[0]<='9'){
			
			int num = 0;
			for(int j=0;j<question.size();j++){
				num*=10;
				num += (int)(question[j]-'0'); 
			}
			cout << dictionary[num] << "\n";
			
		}
		else{
			cout << m.find(question)->second << "\n";
		}
	}
	
}
