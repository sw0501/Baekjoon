#include <iostream>
#include<queue>

using namespace std;

int main() 
{
    int N, H, T;
    cin >> N >> H >> T;
    
    priority_queue<int> pq;
        
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        pq.push(num);
    }
    
    int cnt=0;
    if(pq.top()>=H){
        for( cnt = 1; cnt <= T; cnt++){
        int height = pq.top();
        pq.pop();
        
        if(height>1){
            height /= 2;
        }
        
        pq.push(height);
        if(pq.top()<H){
            break;
        }
    }
    }
    
    
    if(pq.top()>=H){
        cout << "NO" << "\n";
        cout << pq.top() << "\n";
    }
    else{
        cout << "YES" << "\n";
        cout << cnt << "\n";
    }

    return 0;
}