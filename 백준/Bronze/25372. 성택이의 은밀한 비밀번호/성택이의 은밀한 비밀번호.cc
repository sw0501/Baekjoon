#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        string str;
        cin >> str;
        if(str.length()>=6&&str.length()<=9){
            cout << "yes\n";
        }
        else cout << "no\n";
    }
    
    return 0;
}