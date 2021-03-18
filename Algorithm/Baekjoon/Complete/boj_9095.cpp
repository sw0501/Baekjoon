#include<iostream>

using namespace std;

int N;				//테스트 케이스
int DP[15]={0,};	//이동한 칸 수




void init();

int main(){
	
	init();
	
	
	return 0;
}

//총 n칸을 이동하는 방법으로 풀기 가능
void init(){
	cin >> N;
	
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		DP[0]=1;
		for(int j=0;j<num;j++){
			DP[j+1]+=DP[j];
			DP[j+2]+=DP[j];
			DP[j+3]+=DP[j];
		}
		cout << DP[num]<<"\n";
		for(int i=0;i<15;i++){
			DP[i]=0;
		}
	}
}