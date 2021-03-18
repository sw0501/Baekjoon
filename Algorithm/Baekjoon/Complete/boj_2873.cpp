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
	
	//예외가 생기는 R-1줄까지 반복
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
	//R-1번째줄에서 못 밟는 곳이 생기는 경우엔 돌아갈 수가 없으므로 위아래로 밟아가며 진행
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

