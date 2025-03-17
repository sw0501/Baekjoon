#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    string str;
    
    cin >> str;
    
    int A = 1;
    int B = 0;
    int C = 0;
    for(int i=0;i<str.size();i++){
        
        if(str[i]=='A'){
            int tmp = A;
            A = B;
            B = tmp;
        }
        else if(str[i]=='B'){
            int tmp = B;
            B = C;
            C = tmp;
        }
        else if(str[i]=='C'){
            int tmp = C;
            C = A;
            A = tmp;
        }
    }
    
    if(A)cout << 1 << "\n";
        else if(B)cout << 2 << "\n";
            else if(C)cout << 3 << "\n";
    return 0;
}
