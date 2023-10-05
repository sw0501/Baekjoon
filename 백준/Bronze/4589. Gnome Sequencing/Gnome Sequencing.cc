#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    cout << "Gnomes:\n";
    for(int i=0;i<N;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a>b){
            if(b>c){
                cout << "Ordered\n";
            }
            else{
                cout << "Unordered\n";
            }
        }
        else{
            if(b<c){
                cout << "Ordered\n";
            }
            else{
                cout << "Unordered\n";
            }
        }
    }
    
    return 0;
}