#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int A,B;
int m;
stack<int>ar;
stack<int>br;
long long ans=0;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	
	cin >> A >> B >> m;
	
	int num;
	
	//Stack으로 받아서 뒷자리부터 꺼낼 수 있게 함
	for(int i=0;i<m;i++){
		cin >> num;
		ar.push(num);
	}
	
	//꺼낼때마다 자릿수를 늘려서 ans에 저장
	int temp = 1;
	for(int i=m-1;i>=0;i--){
		ans += ar.top()*temp;
		ar.pop();
		temp*=A;
	}
	
	//뒷자리부터 br에 저장
	while(ans>=B){
		br.push(ans%B);
		ans/=B;
	}
	
	//남은 수 저장
	br.push(ans);
	
	//스택이 빌때까지 저장된 수 출력
	while(!br.empty()){
		
		cout << br.top() << " ";
		
		br.pop();
	}
	
}