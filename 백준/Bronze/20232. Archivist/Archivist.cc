#include<iostream>

using namespace std;

string arr[26] = {"ITMO", "SPbSU", "SPbSU", "ITMO", "ITMO","SPbSU", "ITMO", "ITMO", "ITMO", "ITMO","ITMO", "PetrSU, ITMO", "SPbSU", "SPbSU","ITMO", "ITMO", "ITMO", "ITMO", "SPbSU","ITMO", "ITMO", "ITMO", "ITMO", "SPbSU", "ITMO"};

int main(){
    
    int n;
    cin >> n;
    cout << arr[n-1995];
    
    return 0;
    
}