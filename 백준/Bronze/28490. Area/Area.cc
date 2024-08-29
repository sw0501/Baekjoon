#include<iostream>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int M = -1;
    for(int i=0;i<n;i++){
        int h,w;
        cin >> h >> w;
        M = (M>h*w?M:h*w);
    }
    cout << M << "\n";
    
    
    return 0;
}