#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int a,b;
        cin >> a >> b;
        cout << 2 - a + b << "\n";
    }
    
    return 0;
}