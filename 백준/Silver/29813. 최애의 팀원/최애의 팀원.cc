#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    queue<string> q;
    
    unordered_map<string,int> m;
    
    for(int i=0;i<N;i++){
        string c;
        int num;
        cin >> c >> num;
        m.insert({c,num});
        q.push(c);
    }
    
    while(q.size()>1){
        string c = q.front();
        q.pop();
        for(int i=0;i<m[c] - 1;i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    
    cout << q.front();
    
    return 0;
}
