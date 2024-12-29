#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int map[101][101] = {0,};
int visit[101][101] = {0,};

int main() 
{
    // 코드를 작성해주세요
    int N,M,K;
    
    cin >> N >> M >> K;
    
    for(int i=0;i<K;i++){
        int r,c;
        cin >> r >> c;
        map[r-1][c-1] = 1;
    }
    
    int ans = 0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] && !visit[i][j]){
                visit[i][j] = 1;

                queue<pair<int,int>>q;
                
                q.push({i,j});
                
                int temp = 0;
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    
                    temp++;
                    
                    q.pop();
                    
                    for(int k=0;k<4;k++){
                        int tx = x + dx[k];
                        int ty = y + dy[k];
                        
                        if(tx>=0&& tx < N && ty>=0&&ty<M){
                            if(map[tx][ty] && !visit[tx][ty]){
                                visit[tx][ty] = 1;
                                q.push({tx,ty});
                            }
                        }
                    }
                }
                
                if(ans < temp){
                    ans = temp;
                }
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
