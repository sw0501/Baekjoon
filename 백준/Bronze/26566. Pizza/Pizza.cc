#include<iostream>
#include<math.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        double a,b;
        double c,d;
        cin >> a >> b;
        cin >> c >> d;
        
        double S = a/b;
        double W = c*c*M_PI / d;
        
        if(S>W)cout << "Slice of pizza\n";
        else cout << "Whole pizza\n";
    }
    
    
    return 0;
}