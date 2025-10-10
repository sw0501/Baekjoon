#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int dist[20001] = {0,};
    vector<int>node[20001];
    int visit[20001] = {0,};
    
    for(int i=0;i<edge.size();i++){
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<pair<int,int>>q;
    
    q.push({1,0});
    visit[1] = 1;
    
    int max = 0;
    
    while(!q.empty()){
        int num = q.front().first;
        int d = q.front().second;
        
        q.pop();
        
        for(int i=0;i<node[num].size();i++){
            int next = node[num][i];
            if(visit[next])continue;
            dist[next] = d+1;
            
            visit[next] = 1;
            q.push({next,dist[next]});
            
            max = dist[next];
        }
    }
    
    for(int i=1;i<=n;i++){
        if(dist[i]==max)answer++;
    }
    
    return answer;
}