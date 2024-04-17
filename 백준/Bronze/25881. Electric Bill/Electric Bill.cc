#include<iostream>

using namespace std;

int main(){
    
    int S,C;
    cin >> S >> C;
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        int num;
        int cost = 0;
        cin >> num;
        
        cout << num << " ";
        
        if(num <= 1000){
            cost += num * S;
            num = 0;
        }
        else{
            cost += 1000 * S;
            num-=1000;
        }
        
        cost += num * C;
        cout << cost << "\n";
    }
    
    
    return 0;
}