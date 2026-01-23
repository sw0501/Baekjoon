#include<iostream>

using namespace std;

int main(){
    
    int arrM[11] = {0,};
    
    for(int i=0;i<11;i++){
        cin >> arrM[i];
    }
    
    int N;
    cin >> N;
    
    int sum = 0;
    
    for(int i=0;i<N;i++){
        
        int B,S;
        double L;
        
        cin >> B >> L >> S;
        
        if(S>=17 && L >= 2.0){
            sum += arrM[B];
        }
    }
    
    cout << sum << "\n";
    
    return 0;
}