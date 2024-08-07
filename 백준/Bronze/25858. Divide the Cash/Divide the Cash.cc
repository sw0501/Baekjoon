#include<iostream>
#include<vector>

using namespace std;

vector<int>v;

int main(){
    
    int N,D;
    cin >> N >> D;
    
    int sum = 0;
    
    for(int i=0;i<N;i++){
        int num;
        cin >>num;
        v.push_back(num);
        sum+=num;
    }
    
    for(int i=0;i<N;i++){
        cout << D / sum * v[i] << "\n";
    }
    
    return 0;
}