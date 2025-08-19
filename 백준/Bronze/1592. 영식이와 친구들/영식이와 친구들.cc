#include<iostream>

using namespace std;

int main(){
    
    int N,M,L;
    
    cin >> N >> M >> L;
    
    int people[51] = {0,};
    people[1] = 1;
    
    int num = 1;
    int cnt = 0;
    
    while(1){
        if(people[num] == M){
            break;
        }
        
        if(people[num]%2 == 0){
            num -= L;
        }
        else if(people[num]%2 == 1){
            num += L;
        }
        
        if(num<=0){
            num += N;
        }
        else if(num>N){
            num -= N;
        }
        
        people[num]++;
        cnt++;
    }
    
    cout << cnt << "\n";
    
    return 0;
}