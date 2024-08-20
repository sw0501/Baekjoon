#include<iostream>

using namespace std;

int main(){
    
    int N;
    
    cin >> N;
    
    int X=1001,Y=1001;
    
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        
        if(Y>y){
            X = x;
            Y = y;
        }
    }
    cout << X << " " << Y << "\n";
    
    
    return 0;
}