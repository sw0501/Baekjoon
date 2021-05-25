#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

bool S[21];

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	return 0;
}

void init(){
	int N;
	string str;
	
	for(int i=0;i<21;i++){
		S[i] = false;
	}
	
	cin >> N;
		
	for(int i=0;i<N;i++){
		cin >> str;
		if(str=="add"){
			int x;
			cin >> x;
			
			if(!S[x])S[x] = true;
		}
		else if(str=="remove"){
			int x;
			cin >> x;
			if(S[x])S[x] = false;
		}
		else if(str=="check"){
			int x;
			cin >> x;
			cout << S[x] << "\n";
		}
		else if(str=="toggle"){
			int x;
			cin >> x;
			S[x] = !S[x];
		}
		else if(str=="all"){
			fill_n(S,21,true);
		}
		else if(str=="empty"){
			fill_n(S,21,false);
		}
	}
}
