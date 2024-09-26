#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    long long int T, num;
    cin >> T >> num;
    
    long long int ans = 0;
    
    ans = T- 1;
    if(T==1){
        ans += num*8;
    }
    else if(T==5){
        ans += num*8;
    }
    else{
        
        if(num==0){
            ans = T - 1;           
        }
        else{
            ans = 4*num + 1;
            
            if(num%2==0){
                ans += T-2;
            }
            else{
                ans += 4-T;
            }
        }
    }
   
    cout << ans<< "\n";
    
    return 0;
}
