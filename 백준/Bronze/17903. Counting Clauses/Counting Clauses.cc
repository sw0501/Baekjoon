#include<iostream>

using namespace std;

int main(){
    
    int n,m, arr[21][21];
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    if(n>=8){
                cout << "satisfactory" << "\n";
    }
    else{

        cout << "unsatisfactory" << "\n";
    }
    
    return 0;
}