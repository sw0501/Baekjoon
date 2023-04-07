#include<iostream>

using namespace std;

int main(){
    
    int sum[10] = {0,};
    
    int M = 0;
    
    for(int i=0;i<10;i++){
        cin >> sum[i];
        if(i!=0){
            sum[i] += sum[i-1];
        }
    }
    
    for(int i=0;i<10;i++){
        int a = (M-100>0?M-100:100-M);
        int b = (sum[i]-100>0?sum[i]-100:100-sum[i]);
        if(b<=a){
            M = sum[i];
        }
    }
    
    cout << M << "\n";
    
    return 0;
}