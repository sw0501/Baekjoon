#include<iostream>

using namespace std;

int main(){
    
    int a,b;
    int c,d;
    
    cin >> a >> b;
    cin >> c >> d;
    
    if(c<0 && d >= 10){
        cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
    }
    else if(c<a){
        cout << "MCHS warns! Low temperature is expected tomorrow." << "\n";
    }
    else if(d>b){
        cout << "MCHS warns! Strong wind is expected tomorrow." << "\n";
    }
    else{
        cout << "No message" << "\n";
    }
    return 0;
}