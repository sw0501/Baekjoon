#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    string str;
    cin >> str;
    
    int num = 0;
    int ans = 0;
    for(int i=0;i<=str.length();i++){
        if(str[i]>='0' && str[i]<='9'){
            num *= 10;
            num += str[i]-'0';
        }
        else{
            ans += num;
            num = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}
