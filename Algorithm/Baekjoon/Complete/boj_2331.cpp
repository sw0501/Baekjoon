#include<iostream>
#include<algorithm>

using namespace std;

void init();

int Visit[400000] = {0,};
int A,P;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	return 0;
}

void init(){
	cin >> A >> P;
	int C = 1;
	int D = A;
	Visit[A]=C;
	while(1){
		int sum = 0;
		while(D!=0){
			int temp = 1;
			for(int i=0;i<P;i++){
				temp *= D%10;
			}
			sum += temp;
			D /= 10;
		}
		if(Visit[sum]!=0){
			cout << Visit[sum]-1 << "\n";
			break;
		}
		Visit[sum] = ++C;
		D = sum;
	}
}