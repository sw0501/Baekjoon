#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int arr[201][201] = {0,};

struct Virus{
  int gen, num, x, y;
};

struct compare{
    bool operator ()(Virus &v1, Virus &v2){
        if(v1.gen == v2.gen){
            return v1.num>v2.num;
        }
        return v1.gen > v2.gen;
    }  
};

int main() 
{
    // 코드를 작성해주세요
    
    int N,K;
    cin >> N >> K;
    
    //입력
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    
    int S,X,Y;
    cin >> S >> X >> Y;
    
    //바이러스 정렬 PQ
    priority_queue<Virus,vector<Virus>,compare> pq;
    
    //바이러스 보관 큐
    queue<Virus>q;
    
    //바이러스 추가
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]){
                pq.push({0,arr[i][j], i,j});
            }
        }
    }
    
    while(!pq.empty()){
        q.push(pq.top());
        pq.pop();
    }
    
    while(!q.empty()){
        Virus v = q.front();
        q.pop();
        
        if(v.gen >= S)continue;
        
        for(int k=0;k<4;k++){
            int tx = v.x + dx[k];
            int ty = v.y + dy[k];
            
            if(tx>=0&&tx<N&&ty>=0&&ty<N){
                if(!arr[tx][ty]){
                    arr[tx][ty] = v.num;
                    q.push({v.gen + 1, v.num,tx,ty});
                }
            }
        }
    }
    
    cout << arr[X-1][Y-1] << "\n";
    
    return 0;
}
