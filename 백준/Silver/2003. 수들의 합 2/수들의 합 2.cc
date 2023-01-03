#include<iostream>
#include<algorithm>

using namespace std;

int N;
int M;
int arr[1000001];

void init();
int search();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	cout << search() << " ";
}

int search(){
	int C = 0;
	
	int i=0;
	int j=0;
	int S=0;
	while(j<N){
		S+=arr[j++];
		//cout << arr[j-1] << " " << S << "\n";
		while(S>M){
			S-=arr[i++];
		}
		if(S==M){
			C++;
		}
		
	}
	return C;
}