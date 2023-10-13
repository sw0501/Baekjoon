#include<iostream>

using namespace std;

int main(){
    
    int N;
    
    cin >> N;
    
    int P = 5*N - 400;
    
    cout << P << "\n";
    
    if(P>100){
        cout << -1;
    }
    
    else if(P==100){
        cout << 0;
    }
    else cout << 1;
    
    return 0;
}