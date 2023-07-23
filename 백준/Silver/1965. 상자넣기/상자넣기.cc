#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int arr[1000] = {0,};
    int DP[1000] = {0,};
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
        DP[i] = 1;
    }
    
    int max = 0;
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && DP[i] < DP[j]+1){
                DP[i] = DP[j]+1;
            }
        }
        if(max<DP[i])max = DP[i];
    }
    
    cout << max << "\n";
    
    return 0;
}