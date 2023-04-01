#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    for(int n=0;n<N;n++){
        int a;
        string str;
        cin >> a >> str;
        for(int i=0;i<str.length();i++){
            if(a-1==i)continue;
            cout << str[i];
        }
        cout << "\n";
    }
    
    return 0;
}