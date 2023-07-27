#include<iostream>

using namespace std;

int main(){
    
    int y,m,d;
    cin >> y >> m >> d;
    
    int y1,m1,d1;
    cin >> y1 >> m1 >> d1;
    
    
    int a = 0;
    
    if(y1>y){
        if(m1>m){
            a+=y1-y;
        }
        else if(m1==m){
            if(d1>=d){
                a+=y1-y;
            }
            else {
                a += y1 - y -1;
            }
        }
        else {
            a += y1 - y -1;
        }
    }
    else{
        
    }
    
    int b = 1 + (y1-y);
    int c = (y1-y);
    
    cout << a << "\n" << b << "\n" << c << "\n";
    
    
    return 0;
}