#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int cnt = 0;
    
    int drink = 0;
    
    for(int i=0;i<N;i++){
        int milk;
        cin >> milk;
        
        if(milk== drink){
            cnt++;
            drink++;
        }
        
        drink %= 3;
    }
    
    cout << cnt << "\n";
    
    return 0;
}