#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int A = 2;
    int B = 1;
    
    int N;
    cin >> N;
    
    int cnt = 0;
    while(1){
        if(A*A - B*B == N)cnt++;
        
        B--;
        if(B==0){
            A++;
            B = A-1;
            if(A*A - B*B > N)break;
        }
    }
    
    cout << cnt << "\n";
    return 0;
}
