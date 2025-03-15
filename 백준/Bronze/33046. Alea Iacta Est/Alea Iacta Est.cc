#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int A,B;
    int C,D;
    
    cin >> A >> B >> C >> D;
    
    int idx = A + B + C + D;
    
    idx%=4;
    
    if(idx-1 <= 0){
        idx+= 4;
    }
    cout << idx-1 << "\n";
    return 0;
}
