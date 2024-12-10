#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    double total = 0;
    
    for(int i=0;i<N;i++){
        double temp;
        cin >> temp;
        total += temp * temp * temp;
    }
    
    cout.precision(6);
    cout << fixed;
    cout << cbrt(total);
    
    return 0;
}
