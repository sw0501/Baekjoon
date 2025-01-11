#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int n,k,a,b;
    cin >> n >> k >> a >> b;
    
    int stair = n * a - a;
    int elev = (k + n) * b - 2 * b;
    
    cout << elev << " " << stair;
    return 0;
}
