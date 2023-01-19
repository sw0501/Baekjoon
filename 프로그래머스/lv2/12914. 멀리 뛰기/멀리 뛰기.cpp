#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long DP[2001] = {0,};	//Dynamic Programming

long long solution(int n) {
    long long answer = 0;	//정답
   	
   	DP[1] = 1;	//1번 칸은 도달 방법이 1번 // 1
    DP[2] = 2;	//2번 칸은 도달 방법이 2번 // 1+1 , 2
    
    //멀리뛰기는 1칸 또는 2칸 이동이 가능하므로
    //i번째 칸으로 이동할 수 있는 경우는
    //i-1번째 칸에서 1칸 또는 i-2번째 칸에서 2칸 이동하는 경우이다.
    
    //점화식
    //DP[i] = (DP[i-1] + DP[i-2])%1234567
    for(int i=3;i<=n;i++){
        DP[i] = (DP[i-1] + DP[i-2])%1234567;
    }
    
    answer = DP[n] % 1234567;
    
    return answer;
}