#include<iostream>
#include<algorithm>

using namespace std;

long long num;
string str;
int sign = 0;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	
	cin >> num;
	
	//-2진수로 변화
	while(!(num==1||num==0)){
		if(num%(-2)==-1||num%(-2)==1){
			str+="1";
			if(num<0)num-=1;
		}
		else str+="0";
		num = num/(-2);
		//cout << num << "\n";
	}
	
	cout << num;
	
	for(int i=str.length()-1;i>=0;i--){
		cout << str[i];
	}
}

