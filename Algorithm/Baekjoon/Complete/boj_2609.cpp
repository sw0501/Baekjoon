#include<iostream>
#include<algorithm>

using namespace std;

int N,M;

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> M;
	int i=1;
	int ma;	//최소공배수
	int Ma;	//최대공약수
	while(i<=N&&i<=M){
		if(N%i==0&&M%i==0)Ma=i;
		i++;
	}
	ma = N*M/Ma;
	cout << Ma << "\n" << ma;
}
