#include<iostream>

using namespace std;

int main(){
    
    long long N;
    cin >> N;
    
    long long sum = 0;
    int cnt = 0;
    int i = 1;
    while(sum<=N){
        sum  += i;
        i++;
        cnt++;
    }
    cout << cnt - 1;
    
    return 0;
}