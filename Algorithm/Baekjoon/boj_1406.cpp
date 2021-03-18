//연결리스트 이용
//스택?>

#include<iostream>
#include<algorithm>

using namespace std;

string str;
int C;
int M;

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> str;
	C=str.length();
	cin >> M;
	for(int i=0;i<M;i++){
		string s;
		cin >> s;
		if(s=="L"){
			if(C!=0)
				C--;
		}
		if(s=="D"){
			if(C!=str.length())
				C++;
		}
		if(s=="B"){
			if(C!=0){
				str.erase(--C,1);
			}
		}
		if(s=="P"){
			string s2;
			cin >> s2;
			str.insert(C,s2);
			C++;
		}
		//cout << str << "\n";
	}
	cout << str;
}
