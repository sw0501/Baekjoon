#include<iostream>

using namespace std;

int main (){
    
    int a,b,c;
    int d,e,f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    
    if(a*3+b*20+c*120 > d*3+e*20+f*120){
        cout << "Max";
    }
    else if(a*3+b*20+c*120 < d*3+e*20+f*120){
        cout << "Mel";
    }
    else{
        cout << "Draw";
    }
    
    return 0;
}