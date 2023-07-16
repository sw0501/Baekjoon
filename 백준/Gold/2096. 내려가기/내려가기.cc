#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int arr[100001][3] = {0,};
    
    int DP1[3] = {0,};
    int DP2[3] = {0,};
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin >> arr[i][j];
        }
    }
    
    DP1[0] = arr[0][0];
    DP1[1] = arr[0][1];
    DP1[2] = arr[0][2];
    
    for(int i=1;i<N;i++){
        //왼쪽 칸 최대 고르기
        DP2[0] = arr[i][0] + max(DP1[0],DP1[1]);
        //중간 칸 최대 고르기 
        DP2[1] = arr[i][1] + max(DP1[0],max(DP1[1],DP1[2]));
        //마지막 칸 최대 고르기
        DP2[2] = arr[i][2] + max(DP1[1],DP1[2]);
        
        DP1[0] = DP2[0];
        DP1[1] = DP2[1];
        DP1[2] = DP2[2];
    }
    
    cout << max(DP1[0],max(DP1[1],DP1[2])) << " ";
    
    DP1[0] = arr[0][0];
    DP1[1] = arr[0][1];
    DP1[2] = arr[0][2];
    
    for(int i=1;i<N;i++){
        //왼쪽 칸 최소 고르기
        DP2[0] = arr[i][0] + min(DP1[0],DP1[1]);
        //중간 칸 최소 고르기 
        DP2[1] = arr[i][1] + min(DP1[0],min(DP1[1],DP1[2]));
        //마지막 칸 최소 고르기
        DP2[2] = arr[i][2] + min(DP1[1],DP1[2]);
        
        DP1[0] = DP2[0];
        DP1[1] = DP2[1];
        DP1[2] = DP2[2];
    }
    
    cout << min(DP1[0],min(DP1[1],DP1[2]));
    
    return 0;
}