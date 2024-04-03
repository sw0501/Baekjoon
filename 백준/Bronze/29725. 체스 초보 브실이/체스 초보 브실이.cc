#include<iostream>

using namespace std;

int score[1000] = {0,};

int main(){
    
    score['.'] = 0;
    score['K'] = 0;
    score['k'] = 0;
    score['P'] = 1;
    score['p'] = -1;
    score['N'] = 3;
    score['n'] = -3;
    score['B'] = 3;
    score['b'] = -3;
    score['R'] = 5;
    score['r'] = -5;
    score['Q'] = 9;
    score['q'] = -9;
    
    int answer = 0;
    for(int i=0;i<8;i++){
        string str;
        cin >> str;
        for(int j=0;j<8;j++){
            answer += score[str[j]];
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}