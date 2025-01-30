#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int a,d,k;
    
    cin >> a >> d >> k;
    
    if((k-a)%d || (k>a && d <0) || (k<a && d>0)){
        cout << "X";
    }
    else{
        cout << (k-a)/d + 1;
    }
    return 0;
}
