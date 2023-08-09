#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    while(N>=5){
        cout << "V";
        N-=5;
    }
    while(N>0){
        cout << "I";
        N--;
    }
    
    
    return 0;
}