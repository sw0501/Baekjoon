#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    while(1){
        int a,b;
        cin >> a >> b;
        
        if(a==0 && b== 0 )break;
        
        cout << a - (b-a) << "\n";
    }
    return 0;
}
