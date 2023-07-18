#include<iostream>

using namespace std;

int main(){
    
    long long arr[101][101] = {0,};
    long long DP[101][101] = {0,};
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    
    DP[0][0] = 1;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!arr[i][j])break;
            if(i+arr[i][j]<N){
                DP[i+arr[i][j]][j] += DP[i][j]; 
            }
            if(j+arr[i][j]<N){
                DP[i][j+arr[i][j]] += DP[i][j]; 
            }
        }
    }
    
    cout << DP[N-1][N-1] << "\n";
    return 0;
}