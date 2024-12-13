#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N,T;
    cin >> N >> T;
    
    int L = N - T;
    
    cout << T - L << "\n";
    return 0;
}
