#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

int T;				//테스트케이스
void init();
void BFS(int a,int b);
int D(int x);
int S(int x);
int L(int x);
int R(int x);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	//최소횟수를 구하는 문제 : BFS
	cin >> T;
	int a,b;	//a:초기값 b:최종값
	for(int i=0;i<T;i++){
		cin >> a >> b;
		BFS(a,b);
	}
}

void BFS(int a,int b){
	int temp = S(a);
	cout << temp << " ";
	temp = D(temp);
	cout << temp << " ";
	temp = R(temp);
	cout << temp << " ";
	temp = D(temp);
	cout << temp << " ";
	temp = D(temp);
	cout << temp << " ";
	temp = S(temp);
	cout << temp << " ";
	temp = D(temp);
	cout << temp << " ";
	temp = R(temp);
	cout << temp << " ";
	temp = R(temp);
	cout << temp << " ";
}

int D(int x){
	
	if(2*x>9999)return (2*x)%10000;
	return x;
}

int S(int x){
	if(x==0)return 9999;
	return x-1;
}

int L(int x){
	int n[4]={0,};
	for(int i=3;i>=0;i--){
		n[i] = x%10;
		x/=10;
	}
	
	int temp = n[0];
	
	n[0] = n[1];
	n[1] = n[2];
	n[2] = n[3];
	n[3] = temp;
	
	x=0;
	for(int i=0;i<4;i++){
		x*=10;
		x+=n[i];
	}
	return x;
}

int R(int x){
	int n[4]={0,};
	for(int i=3;i>=0;i--){
		n[i] = x%10;
		x/=10;
	}
	
	int temp = n[3];
	
	n[3] = n[2];
	n[2] = n[1];
	n[1] = n[0];
	n[0] = temp;
	
	x=0;
	for(int i=0;i<4;i++){
		x*=10;
		x+=n[i];
	}
	return x;
}
