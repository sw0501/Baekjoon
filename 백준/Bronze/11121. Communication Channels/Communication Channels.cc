#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        string a,b;
        cin >> a >> b;
        if(a==b)cout << "OK\n";
        else cout << "ERROR\n";
    }
    
    return 0;
}