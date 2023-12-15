#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int t = 0;
    int s;
    for(int i=0;i<N;i++){
        cin >> s;
        t += s;
        if(i!=N-1){
            t+=8;
        }
    }
    
    cout << (int)(t/24) << " " << t%24;
    return 0;
}