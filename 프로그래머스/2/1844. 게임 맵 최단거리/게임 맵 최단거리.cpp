#include <vector>
#include <queue>

using namespace std;

struct Pos{
    int x,y,c;
};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int visit[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int N = maps.size();
    int M = maps[0].size();
    
    queue<Pos>q;
    
    q.push({0,0,1});
    visit[0][0] = 1;
    
    while(!q.empty()){
        Pos p = q.front();
        q.pop();
        
        if(p.x == N-1 && p.y == M-1){
            return p.c;
        }
        
        for(int k=0;k<4;k++){
            int tx = p.x + dx[k];
            int ty = p.y + dy[k];
            
            if(tx>=0 && tx<N && ty >=0 && ty<M){
                if(maps[tx][ty] && !visit[tx][ty]){
                    q.push({tx,ty,p.c+1});
                    visit[tx][ty] = 1;
                }
            }
        }
    }
    
    return -1;
}