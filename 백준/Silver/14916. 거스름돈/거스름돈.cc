#include<iostream>

using namespace std;

int main(){
    
    int money;
    cin >> money;
    
    int five = 0;
    int two = 0;
    int ans = money;
    while(five * 5 <= money){
        if((money-five*5)%2 == 0){
            if(ans>five+(money-five*5)/2){
                ans = five+(money-five*5)/2;
            }
        }
        five++;
    }
    
    if(ans == money)cout << -1 << "\n";
    else cout << ans << "\n";
    
    return 0;
}