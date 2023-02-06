#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(int a=0;a*k<=d;a++){
        long long b = sqrt((long long)(d)*d - (a*(long long)k)*(a*(long long)k));
        answer += b/k + 1;
        
    }
    
    
    
    return answer;
}