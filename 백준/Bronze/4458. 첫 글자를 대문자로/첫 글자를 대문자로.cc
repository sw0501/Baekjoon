#include<iostream>
#include<string>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    getchar();
    for(int i=0;i<N;i++){
        string str;
        getline(cin,str);
        if(str[0]>='a' && str[0]<='z'){
            str[0] -= 'a'-'A';
        }
        cout << str << "\n";
    }
    
    return 0;
}