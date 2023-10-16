#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    string str;
    cin >> str;
    
    cout << str[str.length()-5];
    cout << str[str.length()-4];
    cout << str[str.length()-3];
    cout << str[str.length()-2];
    cout << str[str.length()-1];
    
    return 0;
}