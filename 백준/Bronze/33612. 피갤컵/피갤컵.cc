#include<iostream>

using namespace std;

int main(){
    
    int year = 2024;
    int month = 1;
    
    int N;
    cin >> N;
    
    month += N*7;
    
    while(month>12){
        month-=12;
        year++;
    }
    
    cout << year << " " << month << "\n";
    
    return 0;
}