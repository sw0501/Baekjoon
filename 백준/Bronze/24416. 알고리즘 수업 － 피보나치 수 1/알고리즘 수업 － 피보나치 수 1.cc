#include<iostream>

using namespace std;

int cnt = 1;

int fib(int n){
    
    if(n==1 or n==2){
        return 1;
    }
    else {
        cnt++;
        return (fib(n-1) + fib(n-2));
    }
}

int main(){
    
    int N;
    cin >> N;
    
    fib(N);
    
    cout << cnt << " ";
    
    if(N==1 || N==2 ){
        cout << 1 << "\n";
    }
    else{
        cout << N-2 << "\n";
    }
    
    
    return 0;
}