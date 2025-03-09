#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        string str;
        cin >> str;
        
        cout << str.size() << "\n";
    }
    return 0;
}
