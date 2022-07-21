#include<iostream>

using namespace std;

int main(){
    
    int N,W,H,L;
    cin >> N >> W >> H >> L;
    
    if(((int)(W/L))*((int)(H/L))>=N)cout << N;
    else cout <<((int)(W/L))*((int)(H/L));
    
}