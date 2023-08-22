#include<iostream>

using namespace std;

int main(){
    
    int cow[101] = {-1,};
    for(int i=0;i<101;i++){
        cow[i] = -1;
    }
    
    int N,cnt = 0;
    int num, pos;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> num >> pos;
        if(cow[num]==-1){
            cow[num] = pos;
        }
        else{
            if(cow[num] != pos){
                cnt++;
                cow[num] = pos;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}