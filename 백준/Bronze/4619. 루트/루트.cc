#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    while(1){
        int B,N;
        cin >> B >> N;
        
        
        int diff = B-1;
        int A = 1;
        
        if(B==0 && N==0)break;
        
        int i = 2;
        
        while(1){
            int temp = abs(B - pow(i,N));
            if(diff < temp)break;
            diff = temp;
            A = i;
            i++;
        }
        
        cout << A<< "\n";
        
    }
    return 0;
}
