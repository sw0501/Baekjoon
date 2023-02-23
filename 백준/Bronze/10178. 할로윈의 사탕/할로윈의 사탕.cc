#include<iostream>


using namespace std;

int main(){
    
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int a,b;
        cin >> a >> b;
        int c,d;
        c = a/b;
        d = a%b;
        
        cout << "You get " << c << " piece(s) and your dad gets " << d << " piece(s).\n";
        
    }
    
    return 0;
}