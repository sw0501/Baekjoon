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
    
    while(1){
        if(q.empty()){
            break;
        }
        cout << q.front() << " ";
        q.pop();
        if(q.empty()){
            break;
        }
        q.push(q.front());
        q.pop();
    }
    
    return 0;
}