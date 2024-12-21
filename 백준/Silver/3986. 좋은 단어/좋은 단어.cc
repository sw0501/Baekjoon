#include <iostream>
#include <stack>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int N;
    cin >> N;
    
    int cnt = 0;
    for(int i=0;i<N;i++){
        stack<char>st;
        string str;
        cin >> str;
        
        for(int j=0;j<str.size();j++){
            if(!st.empty()){
                if(st.top()==str[j]){
                    st.pop();
                }
                else{
                    st.push(str[j]);
                }
            }
            else{
                st.push(str[j]);
            }
        }
        
        if(st.empty())cnt++;
    }
    
    cout << cnt << "\n";
    return 0;
}
