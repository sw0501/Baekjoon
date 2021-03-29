#include<iostream>
#include<algorithm>

using namespace std;

int L;
int C;
char str[16];
char ans[16];
char CH[5] = {'a','e','i','o','u'};

void init();
void PW(int N,int I);	//N:글자수, I:현재 글자위치
int CK();

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> L >> C;
	for(int i=0;i<C;i++){
		cin >> str[i];
	}
	
	sort(str,str+C);
	
	//최소 1개의 모음과 2개의 자음
	PW(0,0);
}

void PW(int N,int I){
	for(int i=I;i<C;i++){
		ans[N]=str[i];
		if(N==L-1){
			if(CK()){
				for(int j=0;j<L;j++){
					cout << ans[j];
				}
				cout << "\n";
			}
			
		}
		else PW(N+1,i+1);
	}
}

int CK(){
	int O = 0;
	int E = 0;
	for(int i=0;i<L;i++){
		if(ans[i]=='a'||ans[i]=='e'||ans[i]=='i'||ans[i]=='o'||ans[i]=='u')O++;
		else E++;
	}
	if(O>=1&&E>=2)return 1;
	return 0;
}

