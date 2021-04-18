#include<iostream>
#include<algorithm>

using namespace std;

int N;
int C=0;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	
	//N! 뒤의 0의 개수는 5가 곱해진 개수
	cin >> N;
	for(int i=1;i<=N;i++){
		int temp = i;
		//더이상 5의 배수가 아니면 탈출해야함 아니면 버린 값으로 인해서 5의배수가 아닌데 계산이 됨
		if(temp%5==0){
			while(temp>0){
				if(temp%5==0){
					C++;
					temp/=5;
				}
				else break;
			}
		}
	}
	cout << C;
}

