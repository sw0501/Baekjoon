#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct country{
    int n,g,s,d;
};

bool compare(country &a , country &b){
    if(a.g==b.g){
        if(a.s==b.s){
            return a.d>b.d;
        }
        return a.s>b.s;
    }
    return a.g>b.g;
}
int main(){
    
    int N,K;
    cin >> N >> K;
    
    vector<country>v;
    
    for(int i=0;i<N;i++){
        int n,g,s,d;
        cin >> n >> g >> s >> d;
        v.push_back({n,g,s,d});
    }
    
    sort(v.begin(),v.end(),compare);
    
    int rank = 1;
    for(int i=0;i<N;i++){
        if(v[i].n==K){
            cout << rank << "\n";
            break;
        }
        
        if(i<N-1){
            if(v[i].g==v[i+1].g && v[i].s==v[i+1].s&&v[i].d==v[i+1].d)
            continue;
            else{
                rank = i+2;
            }
        }
    }
    
    return 0;
}