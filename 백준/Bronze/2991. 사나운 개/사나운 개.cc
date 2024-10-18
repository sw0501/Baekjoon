#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    
    int P,M,N;
    
    cin >> P >> M >> N;
    
    int p=0,m=0,n=0;
    
    if((P-1)%(A+B)<A){
        p++;
    }
    if((P-1)%(C+D)<C){
        p++;
    }
    
    if((M-1)%(A+B)<A){
        m++;
    }
    if((M-1)%(C+D)<C){
        m++;
    }
    
    if((N-1)%(A+B)<A){
        n++;
    }
    if((N-1)%(C+D)<C){
        n++;
    }
    

    cout << p << "\n" << m << "\n" << n << "\n";
    
    return 0;
}
