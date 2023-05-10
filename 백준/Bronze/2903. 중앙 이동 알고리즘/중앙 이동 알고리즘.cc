#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int p = 3;
    int idx = 2;
    for(int i=1;i<N;i++){
        p = p + idx;
        idx *= 2;
    
    }
    cout << p*p << "\n";
 
    return 0;
}