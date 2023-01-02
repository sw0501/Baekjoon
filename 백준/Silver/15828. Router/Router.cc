
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    queue<int>q;
    
    cin >> N;
    
    int i = 0;
    while(1){
        int temp;
        cin >> temp;
        if(temp==-1)break;
        if(temp==0){
            q.pop();
        }
        else {
            if(q.size()<N){
                q.push(temp);
            }
        }
    }
    
    if(q.empty()){
        cout << "empty!" << "\n";
    }
    else{
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
    }

    return 0;
}
