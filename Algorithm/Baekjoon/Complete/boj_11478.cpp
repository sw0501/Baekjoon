#include <bits/stdc++.h>

using namespace std;

void init();


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	string str;
	cin >> str;
	
	map<string,int>m;
		
	for(int j=1;j<=str.length();j++){
		for(int i=0;i<str.length();i++){
			if(i+j<=str.length()){
				string temp = str.substr(i,j);
				m.insert({temp,1});
			}
		}
	}
	
	
	cout << m.size() << "\n";
}