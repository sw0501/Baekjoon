#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int N,W,H;
    double S;
    cin >> N >> W >> H;
    S = sqrt(W*W+H*H);
    
    int tmp;
    for(int i=0;i<N;i++){
        cin >> tmp;
        if(tmp<=S){
            cout << "DA\n";
        }
        else cout << "NE\n";
    }
    
    return 0;
}