#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int num;
    int cnt = 0;
    while(cin >> num){
        if(num>0)cnt++;
    }
    
    cout << cnt;
    return 0;
}
