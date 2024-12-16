#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int V, E;
bool isConnect[10001] = { 0, };
int parent[10001] = { 0, };
vector<vector<int>>edge;

int id = 0;

//연결 요소 저장
stack<int> st;

//출력
map<int,priority_queue<int,vector<int>,greater<int>>> ans;

//아직 연결되지 않은 요소 중 가장 적은 번호의 정점부터 탐색
int scc(int v) {

    parent[v] = ++id;
    st.push(v);

    int p = parent[v];

    for (int i = 0; i < edge[v].size(); i++) {

        int node = edge[v][i];

        //아직 방문하지 않은 정점
        if (parent[node] == 0) {
            //연결된 노드 중 가장 작은 정점 번호
            p = min(p,scc(node));
        }
        else if (!isConnect[node]) {
            p = min(p, parent[node]);
        }
    }

    if (p == parent[v]) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        //부모노드가 나올 때 까지 stack 비우기
        while (v) {
            int node = st.top();
            st.pop();

            isConnect[node] = true;
            pq.push(node);

            if (node == v)break;
        }

        ans.insert({ pq.top(), pq });
    }

    return p;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;

    for (int i = 0; i <= V; i++) {
        vector<int>v;
        edge.push_back(v);
    }

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
    }

    for (int i = 0; i <= V; i++) {
        sort(edge[i].begin(), edge[i].end());
    }

    for (int i = 1; i <= V; i++) {
        //이미 연결된 요소는 패스
        if (parent[i]==0)
            scc(i);
    }

    cout << ans.size() << "\n";
    
    for (auto it : ans) {
        while (!it.second.empty()) {
            cout << it.second.top() << " ";
            it.second.pop();
        }
        cout << -1 << "\n";
    }
    
   
    return 0;
}