#include<iostream>

using namespace std;

int main(){
    
    int N,M,K;
    cin >> N >> M >> K;
    
    int o;
    int x;
    
    if(M<K)o=M;
    else o=K;
    
    if(N-M<N-K)x=N-M;
    else x = N-K;
    
    cout << o+x << "\n";
    
    
    return 0;
}