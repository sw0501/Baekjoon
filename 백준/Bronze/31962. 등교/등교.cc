#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int N, X;
    
    cin >> N >> X;
    int ans = -1;
    for(int i=0;i<N;i++){
        int S,T;
        cin >> S >> T;
        if(S+T <= X){
           ans = (ans>S?ans:S);
        }
    }
    cout << ans << "\n";
    return 0;
}
