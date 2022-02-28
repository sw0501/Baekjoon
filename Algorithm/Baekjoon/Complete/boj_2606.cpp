#include<iostream>
#include<vector>

using namespace std;

void DFS(int n);

vector<int> v[100];
int ck[100] = {0,};
int N,M;
int ans = -1;

int main(){
    
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    
    DFS(0);
    
    cout << ans << "\n";
    return 0;
}

void DFS(int n){
    ck[n]=1;
    ans++;
    
    for(int i=0;i<v[n].size();i++){
        if(ck[v[n][i]]==0){
            DFS(v[n][i]);
        }
    }
}
