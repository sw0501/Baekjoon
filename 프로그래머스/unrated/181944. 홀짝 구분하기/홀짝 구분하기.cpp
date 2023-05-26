#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    if(n%2){
        cout << n << " is odd";
    }
    else{
        cout << n << " is even";
    }
    return 0;
}