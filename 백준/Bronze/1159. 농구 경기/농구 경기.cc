#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int arr[26] = {0,};
    
    string str;
    
    for(int i=0;i<N;i++){
        cin >> str;
        arr[(int)(str[0]-'a')]++;
    }
    
    int flag = 1;
    for(int i=0;i<26.;i++){
        if(arr[i]>=5){
            flag = 0;
            cout << (char)(i+'a');
        }
    }
    if(flag){
        cout << "PREDAJA";
    }
    
    return 0;
}