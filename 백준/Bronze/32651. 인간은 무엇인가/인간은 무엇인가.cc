#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세
    int N;
    cin >> N;
    
    if(N<=100000 && N%2024 == 0)cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}
