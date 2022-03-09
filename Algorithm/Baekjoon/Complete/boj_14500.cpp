#include <bits/stdc++.h>

using namespace std;

void init();
void CK(int x,int y);
int N,M;
int arr[505][505]={0,};
int answer = 0;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}


void init(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			CK(i,j);
		}
	}
	
	cout << answer << "\n";
}

void CK(int x,int y){
	int temp = 0;
	
	//올바른 범위인 경우 수들의 합 확인
	//if(y+3<M){	//가로 직사각형
		temp = arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x][y+3];
		answer = (answer>temp?answer:temp);
		
	//}
	//if(x+3<N){	//세로 직사각형
		temp = arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+3][y];
		answer = (answer>temp?answer:temp);
	//}
	//if(x+1<N&&y+1<M){	//정사각형
		temp = arr[x][y]+arr[x+1][y]+arr[x+1][y+1]+arr[x][y+1];
		answer = (answer>temp?answer:temp);
	//}
	//6칸의 직사각형만큼만 구하면 모든 범위 체크 가능
	//세로형
	//if(x+2<N&&y+1<M){	
		//ㄴ자 블럭
		temp = arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+2][y+1];
		answer = (answer>temp?answer:temp);
		//대칭 ㄴ자 블럭
		temp = arr[x][y+1]+arr[x+1][y+1]+arr[x+2][y+1]+arr[x+2][y];
		answer = (answer>temp?answer:temp);
		//ㄱ자 블럭
		temp = arr[x][y]+arr[x][y+1]+arr[x+1][y+1]+arr[x+2][y+1];
		answer = (answer>temp?answer:temp);
		//대칭 ㄱ자 블럭
		temp = arr[x][y]+arr[x][y+1]+arr[x+1][y]+arr[x+2][y];
		answer = (answer>temp?answer:temp);
	//}
	//가로형
	//if(x+1<N&&y+2<M){	
		//ㄴ자 블럭
		temp = arr[x][y]+arr[x+1][y]+arr[x+1][y+1]+arr[x+1][y+2];
		answer = (answer>temp?answer:temp);
		//대칭 ㄴ자 블럭
		temp = arr[x][y+2]+arr[x+1][y+2]+arr[x+1][y+1]+arr[x+1][y];
		answer = (answer>temp?answer:temp);
		//ㄱ자 블럭
		temp = arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x+1][y+2];
		answer = (answer>temp?answer:temp);
		//대칭 ㄱ자 블럭
		temp = arr[x][y]+arr[x+1][y]+arr[x][y+1]+arr[x][y+2];
		answer = (answer>temp?answer:temp);
	//}
	//지그재그
	//세로
	//if(x+2<N&&y+1<M){	
		//기본 세로
		temp = arr[x][y]+arr[x+1][y]+arr[x+1][y+1]+arr[x+2][y+1];
		answer = (answer>temp?answer:temp);
		//대칭 세로
		temp = arr[x][y+1]+arr[x+1][y+1]+arr[x+1][y]+arr[x+2][y];
		answer = (answer>temp?answer:temp);
	//}
	//가로
	//if(x+1<N&&y+2<M){	
		//기본 가로
		temp = arr[x][y]+arr[x][y+1]+arr[x+1][y+1]+arr[x+1][y+2];
		answer = (answer>temp?answer:temp);
		//대칭 가로
		temp = arr[x+1][y]+arr[x+1][y+1]+arr[x][y+1]+arr[x][y+2];
		answer = (answer>temp?answer:temp);
	//}
	//ㅗㅜ
	//if(x+1<N&&y+2<M){	
		//ㅜ
		temp = arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x+1][y+1];
		answer = (answer>temp?answer:temp);
		//ㅗ
		temp = arr[x+1][y]+arr[x+1][y+1]+arr[x+1][y+2]+arr[x][y+1];
		answer = (answer>temp?answer:temp);
	//}
	//ㅓㅏ
	//if(x+2<N&&y+1<M){	
		//ㅓ
		temp = arr[x][y+1]+arr[x+1][y+1]+arr[x+2][y+1]+arr[x+1][y];
		answer = (answer>temp?answer:temp);
		//ㅏ
		temp = arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+1][y+1];
		answer = (answer>temp?answer:temp);
	//}
}


