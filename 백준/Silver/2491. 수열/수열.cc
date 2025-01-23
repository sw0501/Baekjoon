#include <iostream>

using namespace std;

int arr[100001] = {0,};
int DP[2][100001] = {0,};

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    //상승 1
    //하락 0
    int flag = 1;
    DP[0][0] = 1;
    DP[1][0] = 1;
    
    for(int i=1;i<N;i++){
        
        if(arr[i] >= arr[i-1])DP[0][i] = DP[0][i-1];
        if(arr[i] <= arr[i-1])DP[1][i] = DP[1][i-1];
        DP[0][i]++;
        DP[1][i]++;
        
    }
    
    int M = 0;
    for(int i=0;i<N;i++){
        M = (M > DP[0][i] ? M : DP[0][i]);
        M = (M > DP[1][i] ? M : DP[1][i]);
    }
    
    cout << M << "\n";
    
    return 0;
}
