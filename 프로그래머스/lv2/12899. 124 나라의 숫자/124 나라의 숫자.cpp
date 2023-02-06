#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    //1 2 3 4  5  6  7  8  9  10 11 12 13
    //1 2 4 11 12 14 21 22 24 41 42 44 111   
        
    
    while(n>0){
        int idx = n%3;
        if(n%3==0){
            answer += "4";
        }
        else if(n%3==1){
            answer += "1";
        }
        else if(n%3==2){
            answer += "2";
        }
        n/=3;
        if(idx==0)n--;
    }
    
    reverse(answer.begin(),answer.end());
    
    return answer;
}