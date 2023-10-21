#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int a = 0;
    int b = 0;
    int e = 0;
    for(int i=0;i<N;i++){
        char c;
        cin >> c;
        if(e==0){
            if(c=='D'){
                a++;
            }
            else {
                b++;
            }
            if(a-b>=2 || a-b<=-2){
                e = 1;
            }
        }
    }
    
    cout << a<<":"<<b<<"\n";
    
    
    return 0;
}