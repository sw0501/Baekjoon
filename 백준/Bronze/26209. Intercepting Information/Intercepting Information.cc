#include<iostream>

using namespace std;

int main(){
    
    int flag = 1;
    for(int i=0;i<8;i++){
        int n;
        cin >> n;
        if(!(n==0||n==1)){
            flag = 0;
        }
    }
    
    if(flag){
        cout << "S";
    }
    else cout << "F";
    
    return 0;
}