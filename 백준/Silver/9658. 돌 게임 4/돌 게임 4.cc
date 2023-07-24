#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int DP[1001] = {0,};    //0 상근 1 창영

    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 0;
    DP[4] = 1;
    
    for(int i=5;i<=N;i++){
        DP[i] = (DP[i-1] && DP[i-3] && DP[i-4] ? 0 : 1);
    }
    
    if(DP[N]==1){
        cout << "SK" << "\n";
    }
    else{
        cout << "CY" << "\n";
    }
    
    
    return 0;
}