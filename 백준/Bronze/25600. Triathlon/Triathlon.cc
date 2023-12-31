#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    int ans = -1;
    for(int i=0;i<N;i++){
        int a,d,g;
        cin >> a >> d >> g;
        int score = a*(d+g);
        if(a==d+g)score *=2;
        
        ans = (ans>score?ans:score);
    }
    
    cout << ans << "\n";
    
    return 0;
}