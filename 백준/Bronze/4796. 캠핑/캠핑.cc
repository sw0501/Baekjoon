#include<iostream>

using namespace std;

int main(){
    
    int L = -1,P = -1,V = -1;
    
    cin >> L >> P >> V;
    int i=1;
    while(L!=0 && P != 0 && V != 0){
        cout << "Case " << i << ": " << V/P*L + (V%P>L?L:V%P) << "\n";
        cin >> L >> P >> V;
        i++;
    }
    
    
    return 0;
}