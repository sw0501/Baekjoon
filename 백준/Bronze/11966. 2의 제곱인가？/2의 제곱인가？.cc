#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    {
        while(N!=1){
            if(N%2!=0){
                cout << 0 << "\n";
                return 0;
            }
            N/=2;
        }
    }
    
    cout << 1 << "\n";
    
    return 0;
}