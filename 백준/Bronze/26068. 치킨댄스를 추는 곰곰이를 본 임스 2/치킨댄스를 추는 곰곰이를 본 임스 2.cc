#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int cnt = 0;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        int temp = 0;
        for(int j=2;j<str.length();j++){
            temp*=10;
            temp += (int)(str[j]-'0');
        }
        if(temp<=90)cnt++;
    }
    
    cout << cnt << "\n";
    return 0;
}