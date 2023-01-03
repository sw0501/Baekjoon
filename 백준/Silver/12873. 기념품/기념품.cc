#include<iostream>
#include<queue>

using namespace std;

int main(){
    
    queue<int> q;
    
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    
    long long level = 1;
    long long stage = 1;
    
    while(q.size()!=1){
        for(int i=0;i<(stage-1)%q.size();i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        level++;
        stage = (long long)(level*level*level);
    }
    
    cout << q.front() << "\n";
    
    return 0;
}