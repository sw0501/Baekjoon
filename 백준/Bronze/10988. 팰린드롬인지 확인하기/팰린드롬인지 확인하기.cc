#include<iostream>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    int flag = 1;
    int i = 0, j=str.length()-1;
    while(i<j){
        if(str[i]!=str[j]){
            flag = 0;
            break;
        }
        i++;
        j--;
    }
    
    cout << flag << "\n";
    
    return 0;
}