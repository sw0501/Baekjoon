#include<iostream>

using namespace std;

int main(){
    
    int N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    
    int ans = 1000000000;
    
    int tmp = A;
    int m = B;
    while(tmp<N){
        tmp += A;
        m += B;
    }
    
    ans = (ans>m?m:ans);
    
    tmp = C;
    m = D;
    while(tmp<N){
        tmp += C;
        m += D;
    }
    
    ans = (ans>m?m:ans);
    
    cout << ans << "\n";
    
    return 0;
}
