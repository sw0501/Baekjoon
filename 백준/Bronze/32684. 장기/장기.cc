#include<iostream>

using namespace std;

int main(){
    
    int value[6] = {13,7,5,3,3,2};
    double score[2] = {0,1.5};
    
    for(int i=0;i<2;i++){
        for(int j=0;j<6;j++){
            int num;
            cin >> num;
            score[i] += value[j] * num;
        }
    }
    
    if(score[0] > score[1]){
        cout << "cocjr0208";
    }
    else{
        cout << "ekwoo";
    }
    
    
    
    return 0;
}