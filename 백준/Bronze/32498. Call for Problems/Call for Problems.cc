#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    int cnt =0;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        
        if(num%2){
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
