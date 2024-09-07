#include<iostream>

using namespace std;

int main(){
    int n;
    string str;
    
    cin >> n >> str;
    
    if(str=="miss")
            cout << n*0 << "\n";
    if(str=="bad")
            cout << n*200 << "\n";
    if(str=="cool")
            cout << n*400 << "\n";
    if(str=="great")
            cout << n*600 << "\n";
    if(str=="perfect")
            cout << n*1000 << "\n";
    
    return 0;
}