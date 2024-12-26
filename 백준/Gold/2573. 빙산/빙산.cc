#include <iostream>
#include <queue>

using namespace std;

int map[301][301] = {0,};
int melt[301][301] = {0,};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() 
{
    // 코드를 작성해주세요
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,M;
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    int t = 1;
    while(1){
        //빙산 녹음
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]){
                    int value = 0;
                    for(int k=0;k<4;k++){
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        
                        if(tx>=0&&tx<N&&ty>=0&&ty<M){
                            if(!map[tx][ty]){
                                value++;
                            }
                        }
                    }
                    melt[i][j] = value;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]){
                    map[i][j] -= melt[i][j];
                    if(map[i][j] < 0){
                        map[i][j] = 0;
                    }
                }
            }
        }
        
        //빙산 개수 카운트
        int cnt = 0;
        int visit[301][301] = {0,};
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j] && !visit[i][j]){
                    queue<pair<int,int>>q;
                    
                    cnt++;
                    visit[i][j] = 1;
                    
                    q.push({i,j});
                    
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(int k=0;k<4;k++){
                            int tx = x + dx[k];
                            int ty = y + dy[k];
                            
                            if(tx>=0&&tx<N&&ty>=0&&ty<M){
                                if(map[tx][ty] && !visit[tx][ty]){
                                    visit[tx][ty]=1;
                                    q.push({tx,ty});
                                }
                            }
                        }
                        
                    }
                }
            }
        }
        
        if(cnt>1){
            cout << t << "\n";
            break;
        }
        else if(cnt==0){
            cout << 0 << "\n";
            break;
        }
        t++;
    }
    
    return 0;
}
