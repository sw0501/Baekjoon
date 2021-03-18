#include<iostream>
#include<algorithm>

using namespace std;

int N;
int M; //최대 8
int arr[9]; //1~8

void init();
void array(int m);

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin>>N>>M;
	for(int i=1;i<=8;i++){
		arr[i]=0;
	}
	array(1);
}

void array(int m){
	for(int i=1;i<=N;i++){
		arr[m]=i;
		int temp=0;
		for(int j=1;j<m;j++){
			if(arr[j]==arr[m])temp=1;
		}
		if(temp)continue;
		if(m==M){
			for(int j=1;j<=M;j++){
				cout<<arr[j]<<" ";
			}
			cout<<"\n";
		}
		else array(m+1);
	}
}