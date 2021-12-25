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
	
	for(int i=0;i<N;i++){
		int S = 0;
		for(int j=i;j<N;j++){
			S += arr[j];
			if(S>=M){
				if(S==M)C++;
				break;
			}
		}
	}
	return C;
}