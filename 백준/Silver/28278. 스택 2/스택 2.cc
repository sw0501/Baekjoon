#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    cin.tie(NULL);
    cout.tie(NULL);
    
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    stack<int>st;
    for(int i=0;i<N;i++){
        int op;
        cin >> op;
        
        if(op==1){
            int X;
            cin >> X;
            st.push(X);
        }
        else if(op==2){
            if(st.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(op==3){
            cout << st.size() << "\n";
        }
        else if(op==4){
            cout << st.empty() << "\n";
        }
        else if(op==5){
            if(st.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << st.top() << "\n";
            }
        }
    }
    
    return 0;
}
