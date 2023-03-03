#include<iostream>

using namespace std;

int main(){
    
    int A,B;
    int N;
    cin >> N;
    int a = 0,b = 0;
    for(int i=0;i<N;i++){
        cin >> A >> B;
        if(A>B){
            a++;
        }
        else if(A<B){
            b++;
        }
    }
    cout << a << " " << b << "\n";
    
    return 0;
}