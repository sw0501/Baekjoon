#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        double a,b;
        cin >> a >> b;
        
        printf("%.1lf\n", abs(a-b));
    }
    
    return 0;
}