#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin  >> N;
    
    int idx = 1;
    int cnt = 0;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        
        if(num != idx)cnt++;
        idx++;
    }
    
    cout << cnt;
    return 0;
}
