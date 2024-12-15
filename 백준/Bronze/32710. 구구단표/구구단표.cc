#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int N;
    cin >> N;
    
    for(int i=2;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(N == i || N == j || N == i * j){
                cout << 1 << "\n";
                return 0;
            }
        }
    }
    
    cout << 0 << "\n";
    
    return 0;
}
