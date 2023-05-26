#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    
    int n=0,m=0;
    
    int answer = 0;
    
    n = a;
    m = b;
    
    int temp_a=a;
    int temp_b=b;
    
    while(temp_b!=0){
        n*=10;
        temp_b/=10;
    }
    n+=b;
    
    while(temp_a!=0){
        m*=10;
        temp_a/=10;
    }
    m+=a;
    
    answer = (n>m?n:m);
    
    return answer;
}