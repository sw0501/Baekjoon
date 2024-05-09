#include<iostream>

using namespace std;

int main(){
    
    int n;
    int sum = 0;
    
    cin >> n;
    
    for(int i=1;i<n+1;i++){
        for(int j=0;j<i+1;j++){
            sum += i + j;
        }
    }
    
    cout << sum;
    
    return 0;
}