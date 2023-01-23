#include<iostream>

using namespace std;

int main(){
    
    int price = 0;
    cin >> price;
    
    int tmp;
    for(int i=0;i<9;i++){
        cin >> tmp;
        price -= tmp;
    }
    
    cout << price << "\n";
    
    
    return 0;
}