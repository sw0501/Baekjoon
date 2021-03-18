#include<iostream>
#include<algorithm>

using namespace std;

string str[1000];
string s;

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> s;
	int L = s.length();
	
	str[0] = s;
	for(int i=1;i<L;i++){
		s.erase(s.begin());
		str[i] = s;
	}
	
	sort(str,str+L);
	
	for(int i=0;i<L;i++){
		cout << str[i] << "\n";
	}
}
