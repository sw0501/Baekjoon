#include<iostream>

using namespace std;

int main(){
    
    long long int R,C,N;
    cin >> R >> C >> N;
    
    long long int x = R/N;
    long long int y = C/N;
    if(R%N)((long long int)(x)++);
    if(C%N)((long long int)(y)++);
    
    cout << ((long long int)(x))*((long long int)(y)) << "\n";
    
    return 0;
}