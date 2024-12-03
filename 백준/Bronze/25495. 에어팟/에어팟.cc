#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int N;
    cin >> N;
    
    int sum = 0;
    int pre = 0;
    int use = 2;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        
        if(pre==num){
            sum += use * 2;
            use *= 2;
        }
        else{
            sum += 2;
            use = 2;
        }
        
        if(sum >= 100){
            pre = 0;
            use = 0;
            sum = 0;        
        }
        else{
            pre = num;    
        }
    }
    
    cout << sum << "\n";
    
    return 0;
}