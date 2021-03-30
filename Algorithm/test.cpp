#include<iostream>
#include<vector>

using namespace std;

int main(){
	
	string N;
	string ans;
	
	cin >> N;
	
	for(int i=0;i<N.length();i++){
		if(N[i]=='7'){
			cout << "111";
		}
		else if(N[i]=='6'){
			cout << "110";
		}
		else if(N[i]=='5'){
			cout << "101";
		}
		else if(N[i]=='4'){
			cout << "100";
		}
		else if(N[i]=='3'){
			if(i==0){
				cout << "11";
			}
			else cout << "011";
		}
		else if(N[i]=='2'){
			if(i==0){
				cout << "10";
			}
			else cout << "010";
		}
		else if(N[i]=='1'){
			if(i==0){
				cout << "1";
			}
			else cout << "001";
		}
		else if(N[i]=='0'){
			if(i==0){
				cout << "0";
			}
			else cout << "000";
		}
	}
	
}