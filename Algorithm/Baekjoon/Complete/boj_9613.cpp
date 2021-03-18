//GCD : 최대공약수
#include<iostream>
#include<algorithm>

using namespace std;

int T;
int N;
int AR[100];
long long S=0;

void init();
void Euclidean(int X,int Y);

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
		cin >> N;
		
		for(int j=0;j<N;j++){
			cin >> AR[j];
		}
		
		sort(AR,AR+N);
		
		S=0;
		
		//모든 경우를 탐색하면서 GCD 계산
		for(int j=0;j<N;j++){
			for(int k=j+1;k<N;k++){
				Euclidean(AR[k],AR[j]);
			}
		}
		
		cout << S << "\n";
		
	}
}

void Euclidean(int X,int Y){
	
	int R = X%Y;
	if(R==0){
		S+=Y;
		return ;
	}
	
	Euclidean(Y,R);
}


