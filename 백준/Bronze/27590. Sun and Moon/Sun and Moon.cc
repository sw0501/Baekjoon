#include<iostream>

using namespace std;

int main(){
    
    int S,pS,M,pM;
    cin >> S >> pS >> M >> pM;
    
    S = pS - S;
    M = pM - M;
    
    while(S!=M){
        if(S<M){
            S += pS;
        }
        else{
            M += pM;
        }
    }
    
    cout << S << "\n";
    return 0;
}