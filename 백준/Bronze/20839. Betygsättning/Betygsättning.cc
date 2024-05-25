#include<iostream>

using namespace std;

int main(){
    
    int x,y,z;
    int a,b,c;
    
    char g='E';
    
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    
    if(c>=z){
        g ='E';
    }
    if(c>=z && b>=(y+1)/2){
        g='D';
    }
    if(c>=z && b>=y){
        g='C';
    }
    if(c>=z && b>=y && a>=(x+1)/2){
        g='B';
    }
    if(c>=z && b>=y && a>=x){
        g='A';
    }
    
    cout << g << "\n";
    
    return 0;
}