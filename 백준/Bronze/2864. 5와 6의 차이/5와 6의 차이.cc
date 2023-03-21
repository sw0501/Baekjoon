#include<iostream>

using namespace std;

int main(){
    
    string str1;
    string str2;
    
    cin >> str1 >> str2;
    
    int sum = 0;
    int temp = 0;
    for(int i=0;i<str1.length();i++){
        temp *= 10;
        if(str1[i]=='6')str1[i]='5';
        temp += (int)(str1[i]-'0');
    }
    sum += temp;
    temp = 0;
    for(int i=0;i<str2.length();i++){
        temp *= 10;
        if(str2[i]=='6')str2[i]='5';
        temp += (int)(str2[i]-'0');
    }
    sum += temp;
    
    cout << sum << " ";
    
    sum = 0;
    temp = 0;
    for(int i=0;i<str1.length();i++){
        temp *= 10;
        if(str1[i]=='5')str1[i]='6';
        temp += (int)(str1[i]-'0');
    }
    sum += temp;
    temp = 0;
    for(int i=0;i<str2.length();i++){
        temp *= 10;
        if(str2[i]=='5')str2[i]='6';
        temp += (int)(str2[i]-'0');
    }
    sum += temp;
    
    cout << sum << " ";
    
    return 0;
}