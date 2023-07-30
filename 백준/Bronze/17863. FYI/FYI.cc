#include<iostream>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    if(str.length()==7 && str[0]=='5' && str[1]=='5' && str[2] =='5'){
        cout << "YES";
    }
    else cout << "NO";
    
    
    return 0;
}