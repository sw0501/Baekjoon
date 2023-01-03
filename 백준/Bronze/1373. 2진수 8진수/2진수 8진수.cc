#include<iostream>
#include<vector>

using namespace std;

int main(){
	
	string N;
	string ans;
	
	cin >> N;
	
	int cnt=0;
	int temp=0;
	for(int i=N.length()-1;i>=0;i--){
		if(cnt==3){
			ans += ((char)temp + '0');
			cnt=0;
			temp=0;
		}
		
		if(cnt==0){
			temp += (int)(N[i]-'0');
		}
		else if(cnt==1){
			temp += 2*(int)(N[i]-'0');
		}
		else if(cnt==2){
			temp += 4*(int)(N[i]-'0');
		}
		cnt++;
	}
	ans += ((char)temp + '0');
	
	for(int i=ans.length()-1;i>=0;i--){
		cout << ans[i];
	}
	
}