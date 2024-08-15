#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int N,M;
    cin >> N >> M;
    
    vector<string>str;
    for(int i=0;i<N;i++)
    {
        string temp;
        cin >> temp;
        
        str.push_back(temp);
    }
    
    int cnt = 0;
    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;
        
        for(int j=0;j<M;j++){
            if(str[i][j] == temp[j]){
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n";
    return 0;
}