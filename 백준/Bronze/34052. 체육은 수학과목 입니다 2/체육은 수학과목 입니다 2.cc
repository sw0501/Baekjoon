#include<iostream>

using namespace std;


int main(){
    
    int sec = 300;
    
    for(int i=0;i<4;i++){
        int num;
        cin >> num;
        
        sec += num;
    }
    
    cout << (sec > 1800 ? "No" : "Yes");
    
    return 0;
}