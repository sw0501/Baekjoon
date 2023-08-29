#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int cnt = 0;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        if(num%2==0){
            cnt++;
        }
        else cnt--;
    }
    
    if(cnt>0)cout << "Happy";
    else cout << "Sad";
    return 0;
}