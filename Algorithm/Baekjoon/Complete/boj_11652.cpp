//문제를 틀렸다면 99퍼센트는 본인의 잘못
#include<iostream>
#include<algorithm>

using namespace std;

int N;
long long AR[1000000];

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> AR[i];
	}
	
	sort(AR,AR+N,less<long long>());
	
	int M=-1;
	long long NUM;
	int temp=1;
	
	for(int i=0;i<N-1;i++){
		//같은 수라면 temp증가
		if(AR[i]==AR[i+1])temp++;
		
		//다른 수라면 temp와 M 비교 후 큰 수 저장 같다면 NUM 비교
		else{
			//cout << AR[i] << " " <<temp << "\n";
			if(temp>M){
				M=temp;
				NUM=AR[i];
			}
			temp = 1;
		}
	}
	
	//cout << AR[N-1] << " " <<temp << "\n";
	
	if(temp>M){
		M=temp;
		NUM=AR[N-1];
		temp=0;
	}
	
	cout << NUM << "\n";
}
