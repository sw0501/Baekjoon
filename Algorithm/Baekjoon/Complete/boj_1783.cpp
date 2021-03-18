#include<iostream>
#include<algorithm>

using namespace std;

int N;
int M;
int C=1;

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	//5칸째 밟을 때부터 모든 이동방법을 다 사용해야하므로 
	//최소한 N 또는 M이 3그리고 7 이상이어야 5칸을 밟을 수 있다.
	cin >> N >> M;
	
	
	//5칸 이상 밟을 수 있다면
	if(N>=3&&M>=7){
		C=M-2;
	}
	//가로로만 길게 이동해야한다면
	else if(N==2){
		C = min(4,(M+1)/2);
	}
	//이동하지 못하는 경우
	else if(N==1){
		C=1;
	}
	//그 외의 경우
	else{
		C=min(M,4);
	}
	
	cout << C << "\n";
}
