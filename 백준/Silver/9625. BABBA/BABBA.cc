#include<iostream>

using namespace std;

int main(){
    
    int DP[2] = {1,0};
    
    int K;
    cin >> K;
    for(int i=0;i<K;i++){
        int A = DP[0];
        int B = DP[1];
        
        DP[1] = A + B;
        DP[0] = B;
    }
    
    cout << DP[0] << " " << DP[1] << "\n";
    
    return 0;
}