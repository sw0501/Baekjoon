#include<iostream>

using namespace std;

int main(){
    
    int avg = 0;
    int pri[1001] = {0,};
    
    int num = 0;
    int cnt = 0;
    for(int i=0;i<10;i++){
        cin >> num;
        avg += num;
        pri[num]++;
    }
    
    num = 0;
    for(int i=10;i<1000;i+=10){
        if(pri[i]>cnt){
            cnt = pri[i];
            num = i;
        }
    }
    
    cout << (int)(avg/10) << "\n" << num << "\n";
    
    return 0;
}