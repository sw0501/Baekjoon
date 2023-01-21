#include<iostream>

using namespace std;

int main(){
    
    int point = 0;
    int M = -1;
    int num = -1;
    for(int i=0;i<5;i++){
        int tmp = 0;
        point = 0;
        for(int j=0;j<4;j++){
            cin >> tmp;
            point += tmp;
        }
        if(point>M){
            num = i+1;
            M = point;
        }
    }
    
    cout << num << " " << M << "\n";
    return 0;
}