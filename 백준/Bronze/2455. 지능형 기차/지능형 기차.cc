#include<iostream>

using namespace std;

int main(){
    
    int num=0;
    int M = -1;
    int p,m;
    
    for(int i=0;i<4;i++){
        cin >> p >> m;
        num -= p;
        num += m;
        M = (num>M?num:M);
    }
    
    cout << M << "\n";
    
    return 0;
}