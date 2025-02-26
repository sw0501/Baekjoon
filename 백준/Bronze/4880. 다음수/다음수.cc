#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    while(1){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==0 && b==0 && c ==0)break;
        if(b-a == c-b){
            cout << "AP " << c + (b-a) << "\n";
        }
        else{
            cout << "GP " << c * (b/a) << "\n";
        }
        
    }
    return 0;
}
