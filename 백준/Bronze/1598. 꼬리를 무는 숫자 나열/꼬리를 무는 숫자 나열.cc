#include<iostream>
#include<cmath>


using namespace std;

int main(){
    
    int a,b;
    cin >> a >> b;
    
    a--;
    b--;
    
    int rowA = a%4;
    int colA = a/4;
    
    int rowB = b%4;
    int colB = b/4;
    
    cout << abs(rowA-rowB) + abs(colA-colB);
        
        
    return 0;
}