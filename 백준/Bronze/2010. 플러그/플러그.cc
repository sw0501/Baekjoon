#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int answer = 0;
    
    int tmp;
    for(int i=0;i<N;i++){
        cin >> tmp;
        answer += tmp;
    }
    answer -= N-1;
    
    cout << answer << "\n";
    
    return 0;
}