#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int num = 11;
    int cnt = 1;
    int N;
    
    cin >> N;
    
    if(N>10){
        while(N>=num){
            num *= 10;
            num + 1;
            cnt++;
            if(num > 1000000000)break;
        }
    }

    
    cout << cnt << "\n";
    
    return 0;
}
