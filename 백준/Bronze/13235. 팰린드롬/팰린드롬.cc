#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    string str;
    cin >> str;
    
    int s = 0;
    int e = str.size()-1;
    
    int flag = 1;
    while(s<e){
        if(str[s]!=str[e]){
            flag = 0;
            break;
        }
        s++;
        e--;
    }
    
    if(flag)cout << "true";
    else cout << "false";
    return 0;
}
