#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N, K;
    cin >> N >> K;
    
    int num;
    int cnt = 0;
    for(int i=0;i<K;i++){
        cin >> num;
        cnt += (num + 1)/2;
    }
    
    if(cnt >= N){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
    
    return 0;
}
