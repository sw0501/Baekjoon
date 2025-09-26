#include<iostream>

using namespace std;

int main(){
    
    
    int T;
    
    cin >> T;
    
    
    long long int fibo[10001] = {0,};
    
    for(int t=1;t<=T;t++){
        
        int P,Q;
        cin >> P >> Q;
        
        fibo[0] = 0 % Q;
        fibo[1] = 1 % Q;
        
        for(int i=2;i<=P;i++){
            fibo[i] = (fibo[i-1] + fibo[i-2]) % Q;
        }
        cout << "Case #" << t << ": " << fibo[P] << "\n";
        
    }
    
    return 0;
}