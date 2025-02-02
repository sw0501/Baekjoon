#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>node[100001];
int visit[100001] = {0,};

int main() 
{
    // 코드를 작성해주세요
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,M,R;
    cin >> N >> M >> R;
    
    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;
        
        node[u].push_back(v);
        node[v].push_back(u);
    }
    
    for(int i=1;i<=N;i++){
        sort(node[i].begin(),node[i].end());
        reverse(node[i].begin(),node[i].end());
    }
    
    visit[R] = 1;
    queue<int>q;
    q.push(R);
    
    int idx = 2;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        
        for(int i=0;i<node[n].size();i++){
            int next = node[n][i];
            if(!visit[next]){
                q.push(next);
                visit[next] = idx++;
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        cout << visit[i] << "\n";
    }
    return 0;
}
