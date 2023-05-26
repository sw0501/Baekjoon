#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    int n = a;
    int temp = b;
    while(temp!=0){
        n*=10;
        temp/=10;
    }
    n+=b;
    
    if(n>2*a*b){
        answer = n;
    }
    else{
        answer = 2*a*b;
    }
    
    return answer;
}