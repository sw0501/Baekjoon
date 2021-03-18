#include<iostream>
#include<stack>

using namespace std;

int N;

int main(){
	
	cin >> N;
	for(int j=0;j<N;j++){
		stack<int>S;
		string str;
		cin >> str;
		int temp = 1;
		for(int i=0;i<str.length();i++){
			if(str[i]=='(')S.push(i);
			else {
				if(S.empty()){
					temp=0;
					break;
				}
				else S.pop();
			}
		}
		if(temp==0||!S.empty())cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
	
	
}

	
	
	