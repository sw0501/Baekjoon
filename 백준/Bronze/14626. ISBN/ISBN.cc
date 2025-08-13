#include <iostream>

using namespace std;

int main(){
    
    string str;
    
    cin >> str;
    
    int weight[2] = {1,3};
    
    int isbn = 0;
    int num = 0;
    
    for(int i=0;i<str.length() - 1;i++){
        if(str[i]=='*'){
            num = weight[i%2];
        }
        else {
            isbn += weight[i%2] * (int)(str[i] - '0');
        }
    }
    
    int m = (int)(str[str.length()-1] - '0');
    
    for(int i=0;i<10;i++){
        if(m == (10 - (isbn + num * i) % 10) % 10){
            cout << i << "\n";
            break;
        }
    }
    
    return 0;
}