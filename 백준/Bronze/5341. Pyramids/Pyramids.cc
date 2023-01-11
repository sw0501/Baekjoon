#include<iostream>

using namespace std;

int main(){
    
    int H;
    cin >> H;
    while(H!=0){
        int cnt = 0;
        for(int i=1;i<=H;i++){
            cnt += i;
        }
        cout << cnt << "\n";
        cin >> H;
    }
    
    return 0;
}