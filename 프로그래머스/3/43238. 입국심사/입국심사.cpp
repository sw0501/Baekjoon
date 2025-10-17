#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    // 심사에 걸리는 시간
    long long left = times[0];
    long long right = (long long)times[times.size()-1] * n;
    
    while(left <= right){
        long long mid = (left + right)/2;
        
        long long check = 0;
        for(int i=0;i<times.size();i++){
            check += (mid/(long long)times[i]);
            if(check >= n)break;
        }
        
        if(check >= n){
            answer = mid;
            right = mid - 1;
        }
        else if(check < n){
            left = mid + 1;
        }
    }
    
    return answer;
}