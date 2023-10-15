#include<iostream>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    int L = str.length();
    int c = 0;
    int u = 0;
    for(int i=0;i<L;i++){
        if(str[i]==':')c++;
        if(str[i]=='_')u++;
    }
    
    cout << L + c + u*5;
    
    
    return 0;
}