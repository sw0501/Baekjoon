#include<iostream>

using namespace std;

int main(){
    
    int ck[26] = {0,};
    
    string str;
    cin >> str;
    
    for(int i=0;i<str.length();i++){
        ck[(int)(str[i]-'A')]++;
    }
    
    if(ck[(int)('M'-'A')]!=0 && ck[(int)('O'-'A')]!=0 && ck[(int)('B'-'A')]!=0 && ck[(int)('I'-'A')]!=0 && ck[(int)('S'-'A')]!=0 )
        cout << "YES";
    else 
        cout << "NO";
    
    return 0;
}