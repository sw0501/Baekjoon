#include <bits/stdc++.h>

using namespace std;

void init();

int N,M;
long long B;
long long T = 999999999;
int height = 0;
int arr[501][501];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> M >> B;
	long long block = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> arr[i][j];
			block+= arr[i][j];
		}
	}
	int avg = (int)((double)block/(N*M) + 0.5);
	
	//인벤토리와 필드에 있는 필요한 흙을 합쳐서 모자를 경우 높이를 낮춘다
	while(avg*N*M>B+block){
		avg--;
	}
	
	//어차피 쌓아놓고 나중에 캐서 복구하는 거는 시간 중요하지 않음
	
	//평균으로 계산되기때문에 버려진 소수점 생각해봐야됨
	avg--;
	for(;avg<=256;avg++){
		long long t_temp = 0;
		if(avg*N*M>B+block)break;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(arr[i][j]>avg){
					t_temp += 2*(arr[i][j]-avg);
				}
				else if(arr[i][j]<avg){
					t_temp += avg - arr[i][j];
				}
			}
		}
		if(t_temp<=T){
			if(t_temp==T){
				height = (avg>height?avg:height);
			}
			else {
				T = t_temp;
				height = avg;
			}
		}
	}
	
	cout << T << " " << height << "\n";
}