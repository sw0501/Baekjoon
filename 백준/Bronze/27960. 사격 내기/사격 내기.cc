#include <iostream>

using namespace std;

int score[10] = {0,};

int main() 
{
    // 코드를 작성해주세요
    int A,C;
    cin >> A >> C;
    
    int s = 1;
    for(int i=1;i<10;i++){
        s*=2;
    }
    
    for(int i=9;i>=0;i--){
        if(A >= s){
            score[i]++;     
            A-=s;
        }
        if(C>=s){
            score[i]++;
            C-=s;
        }
        s/=2;
    }
    
    
    s = 1;
    int ans = 0;
    for(int i=0;i<10;i++){
        if(score[i]==1){
            ans += s;
        }
        s*=2;
    }
    
    cout << ans << "\n";
    
    return 0;
}
