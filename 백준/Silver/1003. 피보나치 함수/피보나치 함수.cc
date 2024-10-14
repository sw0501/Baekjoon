#include <iostream>

using namespace std;


int DP[41][2] = {0,};

int main() 
{
    // 코드를 작성해주세요
    int T;
    cin >> T;

    DP[0][0] = 1;
    DP[0][1] = 0;
    DP[1][0] = 0;
    DP[1][1] = 1;
    for(int i=2;i<41;i++){
        DP[i][0] = DP[i-1][0] + DP[i-2][0];
        DP[i][1] = DP[i-1][1] + DP[i-2][1];
    }
    
    for(int i=0;i<T;i++){
         int num;
        cin >> num;
        
        cout << DP[num][0] << " " << DP[num][1] << "\n";
    }
    
    return 0;
}
