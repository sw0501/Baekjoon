#include<iostream>

using namespace std;

int R,C;
int ar[1002][1002]={0,};
int m=1001;
int mi,mj;

void init();
void O();
void EO();
void EE();

int main(){
    
	init();
	
    return 0;
}

void init(){
	cin >> R >> C;
	
	//기쁨 지수 입력
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cin >> ar[i][j];
			//최소지점 찾기
			if((i+j)%2==1&&m>ar[i][j]){
				m = ar[i][j];
				mi = i;
				mj = j;
			}
		}
	}
	
	//못밟는 지점 확인
	ar[mi][mj]=0;
	
	if(R%2==1)O();
	else if(C%2==1)EO();
	else EE();
}

void O(){
	for(int i=0;i<R;i++){
		for(int j=1;j<C;j++){
			if(i%2==0)cout << "R";
			else cout << "L";
		}
		if(i!=R-1)cout << "D";
	}
}

void EO(){
	for(int j=0;j<C;j++){
		for(int i=1;i<R;i++){
			if(j%2==0)cout << "D";
			else cout << "U";
		}
		if(j!=C-1)cout << "R";
	}
}

void EE(){
	/*
	if(mi==R){
		//ar[R-1][1]까지 경로 출력
		for(int i=1;i<=R-2;i++){
			for(int j=2;j<=C;j++){
				if(i%2==1)cout << "R";
				else cout << "L";
			}
			cout << "D";
		}
		//못 지나가는 곳 갱신
		for(int j=1;j<=C;j++){
			ar[R-2][j]=0;
		}
		//경로 설정
		int i=R-1,j=1;
		ar[i][j]=0;
		while(!(i==R&&j==C)){
			//down
			if(ar[i+1][j]){
				ar[++i][j]=0;
				cout << "D";
			}
			//up
			else if(ar[i-1][j]){
				ar[--i][j]=0;
				cout << "U";
			}
			//right
			else {
				ar[i][++j]=0;
				cout << "R";
			}
		}
	}
	else if(mj==C){
		//ar[1][C-1]까지 경로 출력
		for(int j=1;j<=C-2;j++){
			for(int i=2;i<=R;i++){
				if(j%2==1)cout << "D";
				else cout << "U";
			}
			cout << "R";
		}
		//못 지나가는 곳 갱신
		for(int i=1;i<=R;i++){
			ar[i][C-2]=0;
		}
		int i=1,j=C-1;
		ar[i][j]=0;
		while(!(i==R&&j==C)){
			//right
			if(ar[i][j+1]){
				cout << "R";
				ar[i][++j]=0;
			}
			//left
			else if(ar[i][j-1]){
				cout << "L";
				ar[i][--j]=0;
			}
			//down
			else {
				cout << "D";
				ar[++i][j]=0;
			}
		}
		
	}
	else*/{
		int i=1,j=1;
		ar[i][j]=0;
		int temp = 1;	//진행방향
		while(!(i==R-1&&j==1)){
			//UP
			if(ar[i-1][j]){
				cout << "U";
				ar[--i][j]=0;
			}
			//R/L
			else if(ar[i][j+1]||ar[i][j-1]){
				//Right
				if(temp%2==1){
					cout << "R";
					ar[i][++j]=0;
				}
				//Left
				else{
					cout << "L";
					ar[i][--j]=0;
				}
				
				if(j==C||j==1)temp++;
			}
			//DOWN
			else {
				cout << "D";
				ar[++i][j]=0;
			}
		}
		ar[i][j]=0;
		while(!(i==R&&j==C)){
			//down
			if(ar[i+1][j]){
				ar[++i][j]=0;
				cout << "D";
			}
			//up
			else if(ar[i-1][j]){
				ar[--i][j]=0;
				cout << "U";
			}
			//right
			else {
				ar[i][++j]=0;
				cout << "R";
			}
		}
	}
}

