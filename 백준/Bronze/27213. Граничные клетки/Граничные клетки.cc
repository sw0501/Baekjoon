#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int a,b;
    cin >> a>> b;
    
    cout << a * b - ((a-2 > 0? a-2 : 0) * (b-2 > 0? b-2 : 0));
    return 0;
}
