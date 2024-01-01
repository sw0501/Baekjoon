#include<iostream>
 
using namespace std;
 
int main(){
     
    int num;
    cin >> num;
     
    int ans = 0;
    while(num>0){
        ans += num%10;
        num/=10;
    }
     
    cout << ans << "\n";
     
    return 0;
}