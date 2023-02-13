#include <iostream>
#include <queue>
using namespace std;

int DQ(int n){
    if(n==1){
        return 1;
    }
    
    int ans;
    //짝수
    if(n%2==0){
        ans = DQ(n/2);
    }
    //홀수
    else{
        ans = DQ((n-1)/2) + 1;
    }
    return ans;
}


//5 -> 2 -> 1
//6 -> 3 -> 1
//5000 -> 2500 -> 1250 -> 575 -> 

int solution(int n)
{
    int ans = DQ(n);
    
    
    return ans;
}