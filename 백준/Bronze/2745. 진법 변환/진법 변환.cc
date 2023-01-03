#include<iostream>

using namespace std;

int main(){
	
	string N;
	int B;
	cin >> N >> B;
	
	
	long long ans = 0;
	
	for(int i=0;i<N.length();i++){
		int Z = 1;
		for(int j=N.length()-i-1;j>0;j--){
			Z*=B;
		}
		if(N[i]>='A'&&N[i]<='Z'){
			ans += Z*((int)(N[i]-'A')+10);
		}
		else ans += Z*(int)(N[i]-'0');
	}
	
	cout << ans << "\n";
	
}