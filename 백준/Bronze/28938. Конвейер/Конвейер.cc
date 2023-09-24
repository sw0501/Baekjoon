#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    int answer = 0;
    
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        answer += num;
    }
    
    if(answer>0)cout << "Right";
    else if(answer<0)cout << "Left";
    else cout << "Stay";
    
    
    return 0;
}