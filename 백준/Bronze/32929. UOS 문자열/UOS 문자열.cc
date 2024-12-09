#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    char c[3] = {'U','O','S'};
    int x;
    cin >> x;
    
    cout << c[(x-1)%3] << "\n";
    
    return 0;
}
