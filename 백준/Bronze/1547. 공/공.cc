#include<iostream>

using namespace std;

int main(){
    
    int M;
    
    cin >> M;
    
    int cup = 1;
    
    int x,y;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        if(x==cup){
            cup = y;
        }
        else if(y==cup){
            cup = x;
        }
    }
    
    cout << cup << "\n";
    return 0;
}