#include <string>
#include <vector>

using namespace std;

int Fibo[100001] = {0,};

int solution(int n) {
    int answer = 0;
    
    Fibo[0] = 1;
    Fibo[1] = 1;
    for(int i=2;i<n;i++){
        Fibo[i] = (Fibo[i-1] + Fibo[i-2])%1234567;
    }
    return Fibo[n-1];
}