#include <iostream>
#include <queue>

using namespace std;


int map[1001][1001];
bool visit[1001][1001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() 
{
    // 코드를 작성해주세요
    int N,M;
    cin >> N >> M;
    
    queue<pair<int,int>>jh;
    queue<pair<int,int>>fire;
    queue<pair<int,int>>temp;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c;
            cin >> c;
            if(c=='J'){
                jh.push({i,j});
                visit[i][j] = 1;
            }
            else if(c=='F'){
                fire.push({i,j});
                map[i][j] = 1;
            }
            else if(c=='#'){
                map[i][j] = -1;
            }
        }
    }
    
    int t = 1;
    
    //탈출할 때까지 반복
    while(1){
        //불 먼저 이동
        while(!fire.empty()){
            int x = fire.front().first;
            int y = fire.front().second;
            
            fire.pop();
            
            for(int k=0;k<4;k++){
                int tx = x + dx[k];
                int ty = y + dy[k];
                
                if(tx >=0 && tx<N && ty>=0 && ty<M){
                    if(map[tx][ty] == 0){
                        map[tx][ty] = 1;
                        temp.push({tx,ty});
                    }
                }
            }
        }
        
        while(!temp.empty()){
            fire.push(temp.front());
            temp.pop();
        }
        
        //지훈 이동
        while(!jh.empty()){
            int x = jh.front().first;
            int y = jh.front().second;
            
            jh.pop();
            
            if(x == 0 || y == 0 || x == N-1 || y == M-1){
                cout << t << "\n";
                return 0;
            }
            
            for(int k=0;k<4;k++){
                int tx = x + dx[k];
                int ty = y + dy[k];
                
                if(tx >=0 && tx<N && ty>=0 && ty<M){
                    if(!visit[tx][ty] && map[tx][ty] == 0){
                        visit[tx][ty] = true;
                        temp.push({tx,ty});
                    }
                }
            }
        }
        
        while(!temp.empty()){
            jh.push(temp.front());
            temp.pop();
        }
        t++;
        
        if(jh.empty()){
            cout << "IMPOSSIBLE" << "\n";
            return 0;
        }
    }
    
    
    
    
    return 0;
}
