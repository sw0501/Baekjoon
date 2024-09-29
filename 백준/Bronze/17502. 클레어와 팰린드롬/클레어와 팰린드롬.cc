#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    string str;
    
    cin >> str;
    for(int i=0;i<N;i++){
        if(str[i]=='?'){
            if(str[N-i-1]=='?'){
                str[i]='a';
            }
            else{
                str[i]=str[N-i-1];
            }
        }
    }
    cout << str;
    return 0;
}
