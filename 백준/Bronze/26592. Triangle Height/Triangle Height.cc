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
        
        printf("The height of the triangle is %.2lf units\n",2*a/b);
    }
    
    return 0;
}
