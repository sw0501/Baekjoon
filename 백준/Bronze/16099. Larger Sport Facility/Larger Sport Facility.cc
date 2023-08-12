#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        
        if(a*b > c*d)cout << "TelecomParisTech\n";
        else if(a*b==c*d)cout << "Tie\n";
        else cout << "Eurecom\n";
    }
    
    
    return 0;
}