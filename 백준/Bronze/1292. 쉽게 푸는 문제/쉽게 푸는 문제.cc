#include<iostream>

using namespace std;

int main(){
    
    int arr[1001] = {0,};
    int p = 1;
    int num = 1;
    while(p<=1000){
        for(int i=0;i<num;i++){
            arr[p] = num;
            p++;
            if(p>1000)break;
        }
        num++;
    }
    
    int a,b;
    cin >> a >> b;
    
    int sum = 0;
    for(int i=a;i<=b;i++){
        sum += arr[i];
    }
    cout << sum << "\n";
    
    return 0;
}