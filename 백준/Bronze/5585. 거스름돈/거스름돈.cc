#include<iostream>

using namespace std;

int main(){
    
    int money[6] = {500,100,50,10,5,1};
    
    int num;
    cin >> num;
    num = 1000-num;
    int i = 0;
    int cnt = 0;
    while(i<6){
        if(num>=money[i]){
            cnt += num/money[i];
            num %= money[i];
        }
        i++;
    }
    cout << cnt << "\n";
    return 0;
}