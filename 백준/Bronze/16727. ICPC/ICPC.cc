#include<iostream>

using namespace std;

int main(){
    
    int a,b,c,d;
    cin >> a >> b>> c >> d;
    
    if(a+d>b+c){
        cout << "Persepolis";
    }
    else if(a+d==b+c){
        if(b<d){
            cout << "Persepolis";
        }
        else if(b==d){
            cout << "Penalty";
        }
        else {
            cout << "Esteghlal";    
        }
    }
    else{
        cout << "Esteghlal";
    }
    
    return 0;
}