#include <iostream>
using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    string name;
    int num = -1;
    
    for(int i=0;i<7;i++){
        string str;
        int cnt;
        cin >> str>> cnt;
        if(cnt>num){
            name = str;
            num = cnt;
        }
    }
    cout << name << "\n";
    
    return 0;
}
