#include<iostream>
#include<algorithm>

using namespace std;

//A~Z까지 지났는지를 확인
int CK[26];
//비어있는 공간 고려
char Board[22][22]={0,};
int R,C;
int M=1;

void init();
void Search(int c,int i,int j);

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> R >> C;
	
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cin >> Board[i][j];
		}
	}
	
	//빈공간 미리 채우기
	for(int i=0;i<R+2;i++){
		Board[i][0] = 1;
		Board[i][C+1] = 1;
	}
	for(int j=0;j<C+2;j++){
		Board[0][j] = 1;
		Board[R+1][j] = 1;
	}
	
	for(int i=0;i<R+2;i++){
		for(int j=0;j<C+2;j++){
			cout << Board[i][j];
		}
		cout << "\n";
	}
	
	//첫 번째 문자는 무조건 지나감
	CK[(int)(Board[1][1]-'A')] = 1;
	
	Search(1,1,1);
	
	cout << M;
	
}

void Search(int c,int i,int j){
	//위
	if(!CK[(int)(Board[i-1][j]-'A')]){
		CK[(int)(Board[i-1][j]-'A')] = 1;
		Search(c+1,i-1,j);
		CK[(int)(Board[i-1][j]-'A')] = 0;
	}
	//왼
	if(!CK[(int)(Board[i][j-1]-'A')]){
		CK[(int)(Board[i][j-1]-'A')] = 1;
		Search(c+1,i,j-1);
		CK[(int)(Board[i][j-1]-'A')] = 0;
	}
	//오른
	if(!CK[(int)(Board[i][j+1]-'A')]){
		CK[(int)(Board[i][j+1]-'A')]= 1;
		Search(c+1,i,j+1);
		CK[(int)(Board[i][j+1]-'A')]= 0;
	}
	//아래
	if(!CK[(int)(Board[i+1][j]-'A')]){
		CK[(int)(Board[i+1][j]-'A')] = 1;
		Search(c+1,i+1,j);
		CK[(int)(Board[i+1][j]-'A')] = 0;
	}
	M = (c>M?c:M);
}
