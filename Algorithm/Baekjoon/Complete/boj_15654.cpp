#include <bits/stdc++.h>

using namespace std;

void init();
void NM(int n);

int N,M;
int CK[10001]={0,};
vector<int>arr;
int answer[100001]={0,};


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> M;
	int temp_num;
	for(int i=0;i<N;i++){
		cin >> temp_num;
		arr.push_back(temp_num);
	}
	sort(arr.begin(),arr.end());
	NM(1);
}

void NM(int n){
	for(int i=0;i<N;i++){
		if(CK[arr[i]]==0){
			if(n==M){
				answer[n-1] = arr[i];
				for(int j=0;j<M;j++){
					cout << answer[j] << " ";
				}
				cout << "\n";
			}
			else{
				answer[n-1] = arr[i];
				CK[arr[i]]=1;
				NM(n+1);
				CK[arr[i]]=0;
			}
		}
	}
}
