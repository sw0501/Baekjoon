#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M,C;
    cin >> N;
    
    int arr[100001] = {0,};
    queue<int>q;
    stack<int>s;
    
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    for(int i=1;i<=N;i++){
        cin >> M;
        if(arr[i]==0)s.push(M);
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> C;
        
        q.push(C);
        C = q.front();
        q.pop();
        
        cout << C << " ";
    }

    return 0;
}