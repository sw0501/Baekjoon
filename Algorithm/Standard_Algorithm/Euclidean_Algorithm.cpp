//유클리드 호제법 알고리즘
#include<iostream>
#include<algorithm>

using namespace std;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//X % Y = R 이라고 할때
	//X와 Y의 최대공약수는 Y와 R의 최대 공약수와 같다.
	
	long long X,Y;
	
	cin >> X >> Y;
	
	while(X%Y){
		long long R = X%Y;
		X = Y;
		Y = R;
	}
	
	cout << Y << "\n";
	
	return 0;
}

