#include<iostream>

using namespace std;

int main(){
    
    int N;
    string str[100];
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> str[i];
    }
    
    int row = 0;
    int col = 0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            if(str[i][j]=='.' && str[i][j+1]=='.'){
                row++;
                while(j<N-1 && str[i][j]=='.'){
                    j++;
                }
            }
        }
    }
    
    for(int j=0;j<N;j++){
        for(int i=0;i<N-1;i++){
            if(str[i][j]=='.' && str[i+1][j]=='.'){
                col++;
                while(i<N-1 && str[i][j]=='.'){
                    i++;
                }
            }
        }
    }
    
    cout << row << " " << col << "\n";
    return 0;
}