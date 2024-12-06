#include <iostream>

using namespace std;

int c[101] = {0,};

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> c[i];
    }
    
    int T = 30;
    int cnt = 0;
    for(int i=0; i < N; i++){
        if((double)c[i]/2 <= (double)T){
            cnt++;
        }
        T -= c[i];
        if(T<=0)T = 30;
    }
    
    cout << cnt << "\n";
    
    return 0;
}
