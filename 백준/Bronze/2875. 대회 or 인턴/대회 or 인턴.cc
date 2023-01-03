#include<iostream>

using namespace std;

int main(){
    
	//여학생 2 : 남학생 1 비율로 팀구성
	int N,M,K;	//여 남 인턴
	cin >> N >> M >> K;
	
	//N==2*M이 되도록 조정하는게 그리디
	
	//K를 줄여가면서 비교
	while(K>0){
		if(N>2*M){
			N--;
			K--;
		}
		else {
			M--;
			K--;
		}
	}
	if(N>2*M)cout << M;
	else cout << N/2;
    return 0;
}