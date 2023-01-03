//문자열을 일반 string 으로 풀려고하면 안의 글자 하나 바꿀때마다 O(N) 시간이라서 시간 초과가 난다.
//스택을 이용해서 O(1)로 만들수가 있다.


#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

stack<char>str;
stack<char>temp;
int M;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	string len;
	cin >> len;
	
	for(int i=0;i<len.length();i++){
		str.push(len[i]);
	}
		
	cin >> M;
	
	for(int i=0;i<M;i++){
		string s;
		cin >> s;
		if(s=="L"){
			if(!str.empty()){
				temp.push(str.top());
				str.pop();
			}
				
		}
		if(s=="D"){
			if(!temp.empty()){
				str.push(temp.top());
				temp.pop();
			}
				
		}
		if(s=="B"){
			if(!str.empty()){
				str.pop();
			}
		}
		if(s=="P"){
			string s2;
			cin >> s2;
			for(int j=0;j<s2.length();j++){
				str.push(s2[j]);
			}
		}
	}
	
	char ans[600001];
	int i=0;
	while(!temp.empty()){
		str.push(temp.top());
		temp.pop();
	}
	while(!str.empty()){
		ans[i] = str.top();
		str.pop();
		i++;
	}
	
	for(int L=i-1;L>=0;L--){
		cout << ans[L];
	}
	
	cout << "\n";
}
