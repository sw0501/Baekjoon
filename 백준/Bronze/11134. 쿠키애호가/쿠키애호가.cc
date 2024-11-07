#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int N, C;
        cin >> N >> C;
        
        cout << N / C + (N%C? 1 : 0) << "\n";
    }
    return 0;
}
