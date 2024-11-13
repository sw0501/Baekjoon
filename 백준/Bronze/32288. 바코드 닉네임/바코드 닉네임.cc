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
        cout << (str[i]=='l' ? 'L' : 'i');
    }
    return 0;
}
