#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    queue<int> s;
    stack<int> w;
    
    int N;
    cin >> N;
    
    int idx = 1;
    
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        
        s.push(num);
    }
    
    while(idx <= N){
        if(!s.empty() && s.front() == idx){
            s.pop();
            idx++;
        }
        else if(!w.empty() && w.top() == idx){
            w.pop();
            idx++;
        }
        else{
            if(!s.empty()){
                w.push(s.front());
                s.pop();
            }
        }
        
        if(s.empty() && !w.empty() && w.top() != idx)break;
    }
    
    if(s.empty() && w.empty()){
        cout << "Nice";
    }
    else{
        cout << "Sad";
    }
    
    
    return 0;
}
