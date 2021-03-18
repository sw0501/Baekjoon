#include<iostream>
#include<algorithm>

using namespace std;

int N;
int DP[31]={0,};

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	
	if(N%2==1)cout << 0 << "\n";
	
	else{
		DP[0]=1;
		for(int i=2;i<=N;i+=2){
			DP[i]+=DP[i-2]*3;

			for(int j=4;j<=i;j+=2){
				DP[i]+=DP[i-j]*2;
			}
		}
		cout << DP[N] << "\n";
	}
	
}
