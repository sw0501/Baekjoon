#include<iostream>

using namespace std;

int main(){
    
    int N;
    int i = 0;
    while(1){
        cin >> N;
        if(N==0){
            break;
        }
        i++;
        int temp;
        for(int i=0;i<N;i++){
            cin >> temp;
        }
        cout << "Case " << i << ": Sorting... done!\n";  
    }
    
    return 0;
}