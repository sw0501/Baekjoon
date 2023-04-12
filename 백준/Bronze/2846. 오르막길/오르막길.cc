#include<iostream>

using namespace std;

int main(){
    
    int DP[1000]={0,};
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> DP[i];
    }
    
    int low = DP[0];
    int h = 0;
    for(int i=1;i<N;i++){
        if(DP[i]>DP[i-1]){
            if(DP[i]-low > h){
                h = DP[i]-low;
            }
        }
        else{
            low = DP[i];
        }
    }
    
    cout << h << "\n";
    
    return 0;
    
}