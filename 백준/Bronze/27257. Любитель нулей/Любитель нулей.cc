#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    string str;
    
    cin >> str;
    
    int cnt = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0')cnt++;
    }
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]=='0')cnt--;
        else break;
    }
    
    cout << cnt << "\n";
    
    return 0;
}
