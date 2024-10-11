#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    if(N<=3){
        cout << 4 << "\n";
    }
    else if(N%2)cout << N+1;
    else cout << N;
    return 0;
}
