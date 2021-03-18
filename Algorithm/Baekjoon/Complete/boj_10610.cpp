#include<iostream>

using namespace std;

string str;
int num[10]={0,};

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> str;
	
	int L = str.length();
	int T = 0;
	
	//숫자 개수 카운트
	for(int i=0;i<L;i++){
		int number = (int)(str[i]-'0');
		num[number]++;
		T+=number;
	}
	
	//숫자들의 합이 3의 배수이고 0이 한개 이상 있다면 30의 배수이다.
	//가장 큰 수부터 차례로 출력하면 가장 큰 수
	if(num[0]!=0&&T%3==0){
		for(int i=9;i>=0;i--){
			while(num[i]!=0){
				cout << i;
				num[i]--;
			}
		}
	}
	else cout << "-1" << "\n";
	
	
}