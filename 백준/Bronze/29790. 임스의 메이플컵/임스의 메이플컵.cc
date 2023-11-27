#include<iostream>

using namespace std;

int main(){
    
    int N,U,L;
    cin >> N >> U >> L;
    
    if(N>=1000 && (U>=8000 || L >=260)){
        cout << "Very Good";
    }
    else if(N>=1000){
        cout << "Good";
    }
    else cout << "Bad";
    
    return 0;
}