#include <iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int price;
        cin >> price;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int q,p;
            cin >> q >> p;
            price += q*p;
        }
        cout << price << "\n";
    }
    
    
    return 0;
}