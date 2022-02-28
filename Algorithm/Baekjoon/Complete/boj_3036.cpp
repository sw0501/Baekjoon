#include <bits/stdc++.h>

using namespace std;

void init();
void Div(int r1,int r2);

int N;
int arr[100]={0,};
int decimal[1001];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	
	fill(decimal,decimal+1001,1);
	
	decimal[0] = 0;
	decimal[1] = 0;
	
	for(int i=2;i<=1000;i++){
		if(decimal[i]==1){
			int temp = i*i;
			while(temp<=1001){
				decimal[temp]=0;
				temp*=i;
			}
		}
	}
	
	for(int i=1;i<N;i++){
		Div(arr[0],arr[i]);
	}
}

void Div(int r1,int r2){
	int i = 2;
	while(r1>=i&&r2>=i){
		if(decimal[i]==0){
			i++;
			continue;
		}
		//해당하는 소수가 약수라면 나눠주기
		if(r1%i==0&&r2%i==0){
			r1/=i;
			r2/=i;
		}
		else i++;
	}
	cout << r1 << "/" << r2 << "\n";
}
