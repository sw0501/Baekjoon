#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int T,X;
    cin >> T >> X;
    
    int N;
    int cnt = 0;
    cin >> N;
    
    for(int i=0;i<N;i++){
        int k;
        cin >> k;
        
        for(int i=0;i<k;i++){
            int temp;
            cin >> temp;
            
            if(temp==X)cnt++;
        }
    }
    
    
    if(cnt==N)cout << "YES";
    else cout << "NO";
    return 0;
}
