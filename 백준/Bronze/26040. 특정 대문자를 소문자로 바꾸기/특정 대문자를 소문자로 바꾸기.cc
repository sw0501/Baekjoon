#include <iostream>

using namespace std;

int ch[26] = {0,};

int main() 
{
    // 코드를 작성해주세요
    string str;
    cin >> str;
    getchar();
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        ch[(int)(s[i] - 'A')]++;
        i++;
    }
    
    for(int i=0;i<str.size();i++){
        if(str[i] >='A' && str[i]<='Z' && ch[(int)(str[i]-'A')]){
            str[i] += 'a' - 'A';
        }
    }
    
    cout << str << "\n";
    
    return 0;
}
