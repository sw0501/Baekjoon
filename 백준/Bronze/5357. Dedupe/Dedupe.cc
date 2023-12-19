#include<iostream>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        char c = ' ';
        for(int j=0;j<str.length();j++){
            if(str[j]!=c){
                cout << str[j];
                c = str[j];
            }
        }
        cout << "\n";
    }
    
    return 0;
}