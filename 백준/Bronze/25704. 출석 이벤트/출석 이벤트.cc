#include<iostream>

using namespace std;

int main(){
    

    int N,P;
    cin >> N >> P;
    
    if(N>=20){
        cout << ((P*0.75>P-2000?P-2000:P*0.75)>0?(P*0.75>P-2000?P-2000:P*0.75):0) << "\n";
    }
    else if(N>=15){
        cout << ((P*0.9>P-2000?P-2000:P*0.9)>0?(P*0.9>P-2000?P-2000:P*0.9):0) << "\n";
    }
    else if(N>=10){
        cout << ((P*0.9>P-500?P-500:P*0.9)>0?(P*0.9>P-500?P-500:P*0.9):0) << "\n";
    }
    else if(N>=5){
        cout << ((P-500)>0?P-500:0) << "\n";
    }
    else {
        cout << P << "\n";
    }
    
    return 0;
}