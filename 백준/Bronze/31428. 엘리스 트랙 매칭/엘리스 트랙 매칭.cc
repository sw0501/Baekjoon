#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int cnt[4] = {0,};
    
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        if(str=="C"){
            cnt[0]++;
        }
        else if(str=="S")cnt[1]++;
        else if(str=="I")cnt[2]++;
        else if(str=="A")cnt[3]++;
    }
    
    string str;
    cin >> str;
    
    if(str=="C")cout << cnt[0] << "\n";
    else if(str=="S")cout << cnt[1] << "\n";
    else if(str=="I")cout << cnt[2] << "\n";
    else if(str=="A")cout << cnt[3] << "\n";
    
    return 0;
}