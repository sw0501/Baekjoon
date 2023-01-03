#include<iostream>
#include<algorithm>

using namespace std;

int N,M;
long long ans=0;

char Square[101][101];
int S[101][101]={0,};

void init();

long long SUM(int y1,int x1,int y2,int x2);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N >> M;	
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> Square[i][j];
		}
	}	
	
	
	//누적합을 S에 저장
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + (int)(Square[i][j]-'0');
		}
	}	

		
	//가로로 구분할 때 (N-1)*(N-2)/2 = O(N^2)
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N-1;j++){
			ans = max(ans,SUM(1,1,i,M)*SUM(i+1,1,j,M)*SUM(j+1,1,N,M));
		}
	}
	
	//세로로 구분할 때 (M-1)*(M-2)/2 = O(M^2)
	for(int i=1;i<=M;i++){
		for(int j=i+1;j<=M-1;j++){
			ans = max(ans,SUM(1,1,N,i)*SUM(1,i+1,N,j)*SUM(1,j+1,N,M));
		}
	}
	
	/* 사분면 표시
	12
	34
	*/
	//가운데 점을 기준으로 구분할 때 (N-1)*(M-1) = O(NM)
	for(int i=1;i<=N-1;i++){
		for(int j=1;j<=M-1;j++){
			//ㅗ
			ans = max(ans,SUM(1,1,i,j)*SUM(1,j+1,i,M)*SUM(i+1,1,N,M));
			//ㅓ
			ans = max(ans,SUM(1,1,i,j)*SUM(i+1,1,N,j)*SUM(1,j+1,N,M));
			//ㅜ
			ans = max(ans,SUM(1,1,i,M)*SUM(i+1,1,N,j)*SUM(i+1,j+1,N,M));
			//ㅏ
			ans = max(ans,SUM(1,1,N,j)*SUM(1,j+1,i,M)*SUM(i+1,j+1,N,M));
			}
	}
	
	cout << ans << "\n";
}

//누적합을 이용해 O(1)로 원하는 구간의 합을 구할 수 있다.
long long SUM(int y1,int x1,int y2,int x2){
	//S[y1-1][x1-1]이 중복되서 계산되므로 다시 더해준다.
	return S[y2][x2] - S[y2][x1-1] - S[y1-1][x2] + S[y1-1][x1-1];
}



