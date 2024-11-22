#include <iostream>
#include <queue>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int n;
    cin >> n;
    
    priority_queue<int> pq;
    
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        if(num==0){
            if(pq.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            for(int j=0;j<num;j++){
                int t;
                cin >> t;
                pq.push(t);
            }
        }
        
    }
    
    return 0;
}
