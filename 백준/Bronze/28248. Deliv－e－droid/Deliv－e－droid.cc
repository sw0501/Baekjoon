#include<iostream>

using namespace std;

int main(){
    int P,C;
    cin >> P >> C;
    
    int score = P * 50 - C * 10 + (P>C?500:0);
    
    cout << score << "\n";
    
    return 0;
}