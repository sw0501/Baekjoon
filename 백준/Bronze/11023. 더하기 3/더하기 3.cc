#include<iostream>

using namespace std;

int main(){
    
    int N;
    int sum = 0;
    while(cin >> N){
        sum += N;
    }
    
    cout << sum;
    
    return 0;
}