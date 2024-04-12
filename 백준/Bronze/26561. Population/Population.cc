#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        a += b/4;
        a -= b/7;
        cout << a << "\n";
    }
    
    return 0;
}