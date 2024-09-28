#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    long long int N;
    
    cin >> N;
    
    if(-32768 <= N && N <= 32767 ){
        cout << "short" << "\n";
    }
    else if(-2147483648 <= N && N <= 2147483647){
        cout << "int" << "\n";
    }
    else{
        cout << "long long" << "\n";
    }
    return 0;
}
