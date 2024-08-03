#include<iostream>

using namespace std;

int main(){
    
    int H,W;
    cin >> H >> W;
    
    int m = (H>W?W:H) * 100 / 2;
    
    cout << m << "\n";
    
    return 0;
}