#include<iostream>

using namespace std;

int main(){
    
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    
    int num = 1;
    while(1){
        int cnt = 0;
        if(num%a==0)cnt++;
        if(num%b==0)cnt++;
        if(num%c==0)cnt++;
        if(num%d==0)cnt++;
        if(num%e==0)cnt++;
        if(cnt>=3)break;
        num++;
    }
    cout << num << "\n";
    
    return 0;
}