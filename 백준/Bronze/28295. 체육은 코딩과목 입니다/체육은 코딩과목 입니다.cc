#include<iostream>

using namespace std;

int main(){
    
    char direction[4] = {'N','E','S','W'};
    int idx = 0;
    
    for(int i=0;i<10;i++){
        int n;
        cin >> n;
        
        if(n==1){
            idx++;
        }
        else if(n==2){
            idx+=2;
        }
        else if(n==3){
            idx-=1;
        }
        
        if(idx<0){
            idx+=4;
        }
        else if(idx>3){
            idx-=4;
        }
        
        //cout << direction[idx]<< "\n";
    }
    
    /*
    0 N
    1 W
    2 E
    3 
    4 
    5 
    6 
    7 
    8 
    9 
    10 
    */
    
    cout << direction[idx];
    
    return 0;
}