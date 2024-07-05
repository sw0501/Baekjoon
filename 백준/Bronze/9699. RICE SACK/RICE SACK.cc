#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    
    for(int i=0;i<N;i++){
        int weight = 0;
        for(int j=0;j<5;j++){
            int num;
            cin >> num;
            weight = (weight>num?weight:num);
        }
        cout << "Case #" << i+1 << ": "<< weight << "\n";
    }
    
    return 0;
}