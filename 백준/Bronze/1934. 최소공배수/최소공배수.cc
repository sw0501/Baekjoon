#include<iostream>
#include<algorithm>

using namespace std;

int T;
int A,B;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> T;
	for(int i=0;i<T;i++){
		cin >> A >> B;
		//최대 공약수를 찾고 공식을 이용해 계산
		int x;
		for(int j=1;j<=(A>B?B:A);j++){
			if(A%j==0&&B%j==0)x=j;
		}
		cout << x*(A/x)*(B/x) << "\n";
	}
}
