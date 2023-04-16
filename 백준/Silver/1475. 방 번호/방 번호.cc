#include<iostream>

using namespace std;

int main(){
    
    int num[10] = {0,};
    
    int N;
    cin >> N;
    while(N!=0){
        num[N%10]++;
        N/=10;
    }
    int temp = (num[6]+num[9]);
    if(temp%2 !=0){
        temp++;
    }
    num[6] = temp/2;
    num[9] = temp/2;
    
    int M = 0;
    for(int i=0;i<10;i++){
        if(num[i]>M)
            M = num[i];
    }
    cout << M;
    return 0;
}