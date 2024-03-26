#include<iostream>

using namespace std;

int main(){
    
    double a,b;
    cin >> a >> b;
    while(!(a==0&&b==0)){
        if(a==0||b==0)cout << "AXIS" << "\n";
        else if(a>0 && b>0){
            cout << "Q1" << "\n";
        }
        else if(a<0 && b>0){
            cout << "Q2" << "\n";
        }
        else if(a<0 && b<0){
            cout << "Q3" << "\n";
        }
        else if(a>0 && b<0){
            cout << "Q4" << "\n";
        }
        cin >> a >> b;
    }
    cout << "AXIS" << "\n";
    
    
    return 0;
}