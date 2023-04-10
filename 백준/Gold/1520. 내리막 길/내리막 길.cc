#include<iostream>

using namespace std;

void DFS(int x,int y);

int N,M;
int arr[501][501] = {0,};
int DP[501][501]={0,};
int Fin[501][501]={0,};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }
    
    DP[N-1][M-1] = 1;
    
    DFS(0,0);
    
    cout << DP[0][0] << "\n";
    
    return 0;
}

void DFS(int x,int y){
    
    if(DP[x][y] != 0)return;
    if(x==N-1 && y==M-1)return;
    if(Fin[x][y] != 0)return;
    Fin[x][y] = 1;
    
    for(int k=0;k<4;k++){
        int tx = x + dx[k];
        int ty = y + dy[k];
        if(tx<0||tx>=N||ty<0||ty>=M){
            continue;
        }
        //내려가는 길이라면 현재 경로 더해주기
        if(arr[tx][ty] < arr[x][y]){
            if(DP[tx][ty]!=0){
                DP[x][y] += DP[tx][ty];
            }
            else{
                DFS(tx,ty);
                DP[x][y] += DP[tx][ty];
            }
        }
    }
}

